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

bool cmp(pii &a, pii &b) {
    return (a.fi - a.se) < (b.fi - b.se);
}

int main() {
    int n, m;
    cin >> n >> m;

    ve<pii> ab(n);
    ll sum = 0;

    for (int i = 0; i < n; i++) {
        cin >> ab[i].fi >> ab[i].se;
        sum += ab[i].se;
    }
    sort(ab.begin(), ab.end(), cmp);

    if (sum > m) {
        cout << -1 << endl;
        return 0;
    }

    int song = n;
    for (int i = 0; i < n; i++) {
        sum += (ab[i].fi - ab[i].se);

        if (sum <= m) {
            song--;
        } else {
            break;
        }
    }
    cout << song << endl;

    return 0;
}
