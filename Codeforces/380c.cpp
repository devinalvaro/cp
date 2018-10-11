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
    int best = 0, opens = 0, closes = 0;

    Node() {
    }

    Node(char c) {
        if (c == '(') {
            opens = 1;
        } else {
            closes = 1;
        }
    }

    Node(Node left, Node right) {
        merge(left, right);
    }

    void merge(Node left, Node right) {
        int valid = min(left.opens, right.closes);
        best = left.best + right.best + valid;
        opens = left.opens + right.opens - valid;
        closes = left.closes + right.closes - valid;
    }
};

class SegmentTree {
private:
    string arr;
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
            st[id] = Node(arr[l]);
            return;
        }

        int m = (l + r) / 2;
        build(left(id), l, m);
        build(right(id), m + 1, r);

        st[id].merge(st[left(id)], st[right(id)]);
    }

    Node query(int id, int l, int r, int lq, int rq) {
        if (l > r || l > rq || r < lq) {
            return Node();
        }
        if (l >= lq && r <= rq) {
            return st[id];
        }

        int m = (l + r) / 2;
        return Node(query(left(id), l, m, lq, rq),
                    query(right(id), m + 1, r, lq, rq));
    }

public:
    SegmentTree(string &_arr) {
        arr = _arr;

        st.assign(4 * arr.size(), Node());
        build(0, 0, arr.size() - 1);
    }

    Node query(int lq, int rq) {
        return query(0, 0, arr.size() - 1, lq, rq);
    }
};

int main() {
    string s;
    cin >> s;
    SegmentTree st(s);

    int q;
    scanf("%d", &q);
    while (q--) {
        int l, r;
        scanf("%d %d", &l, &r);

        printf("%d\n", 2 * st.query(l - 1, r - 1).best);
    }

    return 0;
}
