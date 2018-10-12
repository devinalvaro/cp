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
    int zeros, ones, twos;

    Node() {
        zeros = ones = twos = 0;
    }

    Node(int _zeros, int _ones, int _twos) {
        zeros = _zeros;
        ones = _ones;
        twos = _twos;
    }

    Node(const Node &a, const Node &b) {
        zeros = a.zeros + b.zeros;
        ones = a.ones + b.ones;
        twos = a.twos + b.twos;
    }

    void increment() {
        int temp = twos;
        twos = ones;
        ones = zeros;
        zeros = temp;
    }

    void increment(int t) {
        t %= 3;
        while (t--) {
            increment();
        }
    }
};

class SegmentTree {
private:
    int n;
    vector<Node> st;
    vector<int> lazy;

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
            st[id] = Node(1, 0, 0);
            return;
        }

        int m = (l + r) / 2;
        build(left(id), l, m);
        build(right(id), m + 1, r);
        st[id] = Node(st[left(id)], st[right(id)]);
    }

    Node query(int id, int l, int r, int lq, int rq) {
        lazy_update(id, l, r);

        if (l > r || r < lq || rq < l) {
            return Node();
        }
        if (lq <= l && r <= rq) {
            return st[id];
        }

        int m = (l + r) / 2;
        return Node(query(left(id), l, m, lq, rq),
                    query(right(id), m + 1, r, lq, rq));
    }

    void update(int id, int l, int r, int lq, int rq) {
        lazy_update(id, l, r);

        if (l > r || r < lq || rq < l) {
            return;
        }
        if (lq <= l && r <= rq) {
            st[id].increment();

            if (l != r) {
                lazy[left(id)] += 1;
                lazy[right(id)] += 1;
            }
            return;
        }

        int m = (l + r) / 2;
        update(left(id), l, m, lq, rq);
        update(right(id), m + 1, r, lq, rq);
        st[id] = Node(st[left(id)], st[right(id)]);
    }

    void lazy_update(int id, int l, int r) {
        if (lazy[id] == 0) {
            return;
        }

        st[id].increment(lazy[id]);

        if (l != r) {
            lazy[left(id)] += lazy[id];
            lazy[right(id)] += lazy[id];
        }
        lazy[id] = 0;
    }

public:
    SegmentTree(int _n) {
        n = _n;

        st.assign(4 * n, Node(1, 0, 0));
        build(0, 0, n - 1);

        lazy.assign(4 * n, false);
    }

    Node query(int lq, int rq) {
        return query(0, 0, n - 1, lq, rq);
    }

    void update(int lq, int rq) {
        update(0, 0, n - 1, lq, rq);
    }
};

int main() {
    int n, q;
    scanf("%d %d", &n, &q);

    SegmentTree st(n);

    while (q--) {
        int t, lq, rq;
        scanf("%d %d %d", &t, &lq, &rq);

        if (t == 0) {
            st.update(lq, rq);
        } else {
            printf("%d\n", st.query(lq, rq).zeros);
        }
    }

    return 0;
}
