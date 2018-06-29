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

int main() {
    int n;
    cin >> n;

    ve<pll> points;

    for (int i = 0; i < n; i++) {
        ll l, r;
        cin >> l >> r;

        points.pb({l, 1});
        points.pb({r + 1, -1});
    }

    sort(points.begin(), points.end());

    int cnt = 0;
    um<int, ll> ans;

    for (int i = 0; i < points.size(); i++) {
        cnt += points[i].se;
        if (i + 1 < points.size()) {
            ans[cnt] += points[i + 1].first - points[i].first;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << (i == n ? '\n' : ' ');
    }

    return 0;
}
