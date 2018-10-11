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

class SegmentTree {
private:
    vector<int> arr, st;

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

    int query(int id, int l, int r, int lq, int rq) {
        if (l > r || l > rq || r < lq) {
            return 0;
        }
        if (l >= lq && r <= rq) {
            return st[id];
        }

        int m = (l + r) / 2;
        return query(left(id), l, m, lq, rq) +
               query(right(id), m + 1, r, lq, rq);
    }

    void update(int id, int l, int r, int q) {
        if (l > r || l > q || r < q) {
            return;
        }
        if (l >= q && r <= q) {
            st[id] = 1;
            return;
        }

        int m = (l + r) / 2;
        update(left(id), l, m, q);
        update(right(id), m + 1, r, q);

        st[id] = st[left(id)] + st[right(id)];
    }

public:
    SegmentTree(vector<int> &_arr) {
        arr = _arr;

        st.assign(4 * arr.size(), 0);
        build(0, 0, arr.size() - 1);
    }

    int query(int lq, int rq) {
        return query(0, 0, arr.size() - 1, lq, rq);
    }

    void update(int q) {
        return update(0, 0, arr.size() - 1, q);
    }
};

struct Element {
    int type, val, order;
    int i, j;

    Element(int _i, int _j, int _val, int _order) {
        type = 0;
        i = _i;
        j = _j;
        val = _val;
        order = _order;
    }

    Element(int _val, int _order) {
        type = 1;
        val = _val;
        order = _order;
    }

    bool operator<(const Element &e) {
        if (val == e.val) {
            return type < e.type;
        }
        return val > e.val;
    }
};

int main() {
    int n;
    scanf("%d", &n);

    ve<Element> elems;
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        elems.pb(Element(a, i));
    }

    int q;
    scanf("%d", &q);
    while (q--) {
        int i, j, k;
        scanf("%d %d %d", &i, &j, &k);
        elems.pb(Element(i - 1, j - 1, k, q));
    }
    sort(elems.begin(), elems.end());

    ve<int> a(n);
    SegmentTree st(a);

    ve<pii> ans;
    for (Element &e : elems) {
        if (e.type == 0) {
            ans.pb({e.order, st.query(e.i, e.j)});
        } else {
            st.update(e.order);
        }
    }

    sort(ans.rbegin(), ans.rend());
    for (int i = 0; i < ans.size(); i++) {
        printf("%d\n", ans[i].se);
    }

    return 0;
}
