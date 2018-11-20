/* Xenia and Bit Operations */

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
    vector<int> arr, st;

    int left(int id) {
        return (id << 1) + 1;
    }

    int right(int id) {
        return (id << 1) + 2;
    }

    void build(int id, int l, int r, bool OR) {
        if (l > r) {
            return;
        }
        if (l == r) {
            st[id] = arr[l];
            return;
        }

        int m = (l + r) / 2;
        build(left(id), l, m, !OR);
        build(right(id), m + 1, r, !OR);

        if (OR) {
            st[id] = st[left(id)] | st[right(id)];
        } else {
            st[id] = st[left(id)] ^ st[right(id)];
        }
    }

    int query(int id, int l, int r, int lq, int rq) {
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

    void update(int id, int l, int r, int q, int b, bool OR) {
        if (q < l || r < q || l > r) {
            return;
        }
        if (l == r) {
            st[id] = b;
            return;
        }

        int m = (l + r) / 2;
        update(left(id), l, m, q, b, !OR);
        update(right(id), m + 1, r, q, b, !OR);

        if (OR) {
            st[id] = st[left(id)] | st[right(id)];
        } else {
            st[id] = st[left(id)] ^ st[right(id)];
        }
    }

public:
    SegmentTree(vector<int> &_arr, int p) {
        arr = _arr;

        st.assign(4 * arr.size(), 0);

        if (p & 1) {
            build(0, 0, arr.size() - 1, true);
        } else {
            build(0, 0, arr.size() - 1, false);
        }
    }

    int query(int lq, int rq) {
        return query(0, 0, arr.size() - 1, lq, rq);
    }

    void update(int q, int b, bool OR) {
        update(0, 0, arr.size() - 1, q, b, OR);
    }
};

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int len = pow(2, n);
    vec<int> a(len);
    for (int i = 0; i < len; i++) {
        scanf("%d", &a[i]);
    }

    SegmentTree st(a, n);
    while (m--) {
        int p, b;
        scanf("%d %d", &p, &b);
        p--;

        if (n & 1) {
            st.update(p, b, true);
        } else {
            st.update(p, b, false);
        }
        printf("%d\n", st.query(0, len - 1));
    }

    return 0;
}
