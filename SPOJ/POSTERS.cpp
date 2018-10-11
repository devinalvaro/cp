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

set<int> nums;

class SegmentTree {
private:
    int n;
    vector<int> lazy;

    int left(int id) {
        return (id << 1) + 1;
    }

    int right(int id) {
        return (id << 1) + 2;
    }

    void update(int id, int l, int r, int lq, int rq, int val) {
        if (l > r || l > rq || r < lq) {
            return;
        }
        if (l >= lq && r <= rq) {
            lazy[id] = val;
            return;
        }

        lazy_update(id, l, r);

        int m = (l + r) / 2;
        update(left(id), l, m, lq, rq, val);
        update(right(id), m + 1, r, lq, rq, val);
    }

    void lazy_update(int id, int l, int r) {
        if (lazy[id]) {
            if (l != r) {
                lazy[left(id)] = lazy[id];
                lazy[right(id)] = lazy[id];
            }
            lazy[id] = 0;
        }
    }

    void unslack(int id, int l, int r) {
        if (lazy[id]) {
            nums.insert(lazy[id]);
            return;
        }

        if (l != r) {
            int m = (l + r) / 2;
            unslack(left(id), l, m);
            unslack(right(id), m + 1, r);
        }
    }

public:
    SegmentTree(int _n) {
        n = _n;
        lazy.assign(4 * n, 0);
    }

    void update(int lq, int rq, int val) {
        update(0, 0, n - 1, lq, rq, val);
    }

    void unslack() {
        unslack(0, 0, n - 1);
    }
};

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        nums.clear();

        int n;
        scanf("%d", &n);

        int len = 0;

        ve<pii> qs(n);
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &qs[i].fi, &qs[i].se);
            len = max(len, qs[i].se);
        }

        SegmentTree st(len);
        for (int i = 0; i < n; i++) {
            st.update(qs[i].fi - 1, qs[i].se - 1, i + 1);
        }
        st.unslack();

        printf("%d\n", nums.size());
    }

    return 0;
}
