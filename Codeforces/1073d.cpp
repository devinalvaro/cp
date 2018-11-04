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

#define ceil(x, y) (x + y - 1) / y
#define spnl(i, n) " \n"[(i == n - 1)]

struct Node {
    ll cost;
    int cnt;

    Node() {
        cost = 0, cnt = 1;
    }

    Node(ll cost_, int cnt_) {
        cost = cost_, cnt = cnt_;
    }

    Node(const Node &a, const Node &b) {
        cost = a.cost + b.cost;
        cnt = a.cnt + b.cnt;
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
            st[id] = Node(arr[l], 1);
            return;
        }

        int m = (l + r) / 2;
        build(left(id), l, m);
        build(right(id), m + 1, r);
        st[id] = Node(st[left(id)], st[right(id)]);
    }

    Node query(int id, int l, int r, int lq, int rq) {
        if (l > r || r < lq || rq < l) {
            return Node(0, 0);
        }
        if (lq <= l && r <= rq) {
            return st[id];
        }

        int m = (l + r) / 2;
        return Node(query(left(id), l, m, lq, rq),
                    query(right(id), m + 1, r, lq, rq));
    }

    void update(int id, int l, int r, int lq, int rq, ll cost, int cnt) {
        if (l > r || r < lq || rq < l) {
            return;
        }
        if (lq <= l && r <= rq) {
            st[id] = Node(cost, cnt);
            return;
        }

        int m = (l + r) / 2;
        update(left(id), l, m, lq, rq, cost, cnt);
        update(right(id), m + 1, r, lq, rq, cost, cnt);
        st[id] = Node(st[left(id)], st[right(id)]);
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

    void update(int lq, int rq, ll cost, int cnt) {
        update(0, 0, arr.size() - 1, lq, rq, cost, cnt);
    }
};

int main() {
    int n;
    ll t;
    scanf("%d %lld", &n, &t);

    ve<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    SegmentTree st(a);

    ll cnt = 0;
    while (true) {
        Node q = st.query(0, n - 1);
        cnt += (t / q.cost) * q.cnt;
        t = t % q.cost;

        for (int i = 0; i < n; i++) {
            if (t < st.query(0, i).cost) {
                st.update(i, i, 0, 0);
            }
        }

        q = st.query(0, n - 1);
        if (t == 0 || q.cnt == 0 || t < q.cost) {
            break;
        }
    }
    printf("%lld\n", cnt);

    return 0;
}
