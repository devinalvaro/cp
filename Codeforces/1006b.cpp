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

bool cmp(const pii &a, const pii &b) {
    if (a.fi == b.fi) {
        return a.se > b.se;
    }
    return a.fi > b.fi;
}

bool cmp2(const pii &a, const pii &b) {
    return a.se < b.se;
}

int main() {
    int n, k;
    cin >> n >> k;

    ve<pii> a(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        a.pb({x, i + 1});
    }

    sort(a.begin(), a.end(), cmp);
    sort(a.begin(), a.begin() + k, cmp2);

    int sum = 0;
    for (int i = 0; i < k; i++) {
        sum += a[i].fi;
    }
    cout << sum << endl;

    if (k == 1) {
        cout << n << endl;
    } else {
        cout << a[0].se;
        for (int i = 1; i + 1 < k; i++) {
            cout << ' ' << a[i].se - a[i - 1].se;
        }
        cout << ' ' << n - a[k - 2].se << endl;
    }

    return 0;
}
