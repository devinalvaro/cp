/* Range Sum */

#include <bits/stdc++.h>

using namespace std;

// clang-format off
#define ll  long long
#define fi  first
#define se  second
#define pb  push_back
#define us  unordered_set
#define um  unordered_map
#define pq  priority_queue
#define vec vector
#define pii pair<int, int>
#define pll pair<ll, ll>

#define ceil(x, y) ((x + y - 1) / y)
#define spnl(i, n) (i == n - 1 ? '\n' : ' ')

#define eps 1e-9
#define pi  acos(-1)
// clang-format on

class SegmentTree {
private:
    vector<int> arr, lazy;
    vector<ll> st;

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
        st[id] = st[left(id)] + st[right(id)];
    }

    ll query(int id, int l, int r, int lq, int rq) {
        lazy_update(id, l, r);

        if (l > r || r < lq || rq < l) {
            return 0;
        }
        if (lq <= l && r <= rq) {
            return st[id];
        }

        int m = (l + r) / 2;
        return query(left(id), l, m, lq, rq) +
               query(right(id), m + 1, r, lq, rq);
    }

    void update(int id, int l, int r, int lq, int rq, int diff) {
        lazy_update(id, l, r);

        if (l > r || r < lq || rq < l) {
            return;
        }
        if (lq <= l && r <= rq) {
            st[id] += (r - l + 1) * diff;

            if (l != r) {
                lazy[left(id)] += diff;
                lazy[right(id)] += diff;
            }
            return;
        }

        int m = (l + r) / 2;
        update(left(id), l, m, lq, rq, diff);
        update(right(id), m + 1, r, lq, rq, diff);
        st[id] = st[left(id)] + st[right(id)];
    }

    void lazy_update(int id, int l, int r) {
        if (lazy[id] == 0) {
            return;
        }

        st[id] += (r - l + 1) * lazy[id];

        if (l != r) {
            lazy[left(id)] += lazy[id];
            lazy[right(id)] += lazy[id];
        }
        lazy[id] = 0;
    }

public:
    SegmentTree(vector<int> &_arr) {
        arr = _arr;

        st.assign(4 * arr.size(), 0);
        build(0, 0, arr.size() - 1);

        lazy.assign(4 * arr.size(), 0);
    }

    ll query(int lq, int rq) {
        return query(0, 0, arr.size() - 1, lq, rq);
    }

    void update(int lq, int rq, int diff) {
        update(0, 0, arr.size() - 1, lq, rq, diff);
    }
};

int main() {
    int n;
    scanf("%d", &n);

    vec<int> a(2e5);
    for (int i = n - 1; i >= 0; i--) {
        scanf("%d", &a[i]);
    }

    int last = n - 1;
    SegmentTree st(a);

    int q;
    scanf("%d", &q);
    while (q--) {
        int t;
        scanf("%d", &t);

        if (t == 1) {
            int l, r;
            scanf("%d %d", &l, &r);
            l--, r--;

            int lq = last - r, rq = last - l;
            printf("%lld\n", st.query(lq, rq));
        } else if (t == 2) {
            int x;
            scanf("%d", &x);

            last++;
            st.update(last, last, x);
        }
    }

    return 0;
}
