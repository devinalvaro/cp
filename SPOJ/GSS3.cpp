#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define ll long long
#define ve vector
#define pq priority_queue
#define um unordered_map
#define us unordered_set

#define pii pair<int, int>
#define pll pair<ll, ll>

struct Node {
    int best, prefixBest, suffixBest, sum;

    Node() {
        best = prefixBest = suffixBest = sum = 0;
    }

    Node(int val) {
        best = prefixBest = suffixBest = sum = val;
    }

    Node(Node left, Node right) {
        merge(left, right);
    }

    void merge(Node left, Node right) {
        best =
            max(max(left.best, right.best), left.suffixBest + right.prefixBest);
        prefixBest = max(left.prefixBest, left.sum + right.prefixBest);
        suffixBest = max(right.suffixBest, right.sum + left.suffixBest);
        sum = left.sum + right.sum;
    }

    void update(int diff) {
        best += diff;
        prefixBest += diff;
        suffixBest += diff;
        sum += diff;
    }
};

class SegmentTree {
private:
    vector<int> arr;
    vector<Node> st;

    int left(int id) {
        return (id << 1) + 1;
    }

    int right(int id) {
        return (id << 1) + 2;
    }

    void build(int id, int l, int r) {
        if (l > r) {
            return;
        }
        if (l == r) {
            st[id] = arr[l];
            return;
        }

        int m = (l + r) / 2;
        build(left(id), l, m);
        build(right(id), m + 1, r);

        st[id].merge(st[left(id)], st[right(id)]);
    }

    Node query(int id, int l, int r, int lq, int rq) {
        if (l > r || l > rq || r < lq) {
            Node node(-1e9);
            node.sum = 0;
            return node;
        }
        if (l >= lq && r <= rq) {
            return st[id];
        }

        int m = (l + r) / 2;
        return Node(query(left(id), l, m, lq, rq),
                    query(right(id), m + 1, r, lq, rq));
    }

    void update(int id, int l, int r, int lq, int rq, int diff) {
        if (l > r || l > rq || r < lq) {
            return;
        }
        if (l >= lq && r <= rq) {
            st[id].update(diff);
            return;
        }

        int m = (l + r) / 2;
        update(left(id), l, m, lq, rq, diff);
        update(right(id), m + 1, r, lq, rq, diff);

        st[id].merge(st[left(id)], st[right(id)]);
    }

public:
    SegmentTree(vector<int> &_arr) {
        arr = _arr;

        st.assign(4 * arr.size(), Node());
        build(0, 0, arr.size() - 1);
    }

    Node query(int lq, int rq) {
        return query(0, 0, arr.size() - 1, lq, rq);
    }

    void update(int lq, int rq, int diff) {
        update(0, 0, arr.size() - 1, lq, rq, diff);
    }
};

int main() {
    int n;
    scanf("%d", &n);

    ve<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    SegmentTree st(a);

    int q;
    scanf("%d", &q);
    while (q--) {
        int t, x, y;
        scanf("%d %d %d", &t, &x, &y);

        if (t == 0) {
            int diff = y - a[x - 1];
            a[x - 1] += diff;
            st.update(x - 1, x - 1, diff);
        } else {
            printf("%d\n", st.query(x - 1, y - 1).best);
        }
    }
}
