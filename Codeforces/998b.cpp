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
    int n, b;
    cin >> n >> b;

    ve<int> a(n);
    ve<pii> oe(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];

        oe[i] = (a[i] & 1) ? make_pair(1, 0) : make_pair(0, 1);
        if (i > 0) {
            oe[i].first += oe[i - 1].first;
            oe[i].second += oe[i - 1].second;
        }
    }

    ve<int> cuts;
    for (int i = 0; i < n - 1; i++) {
        if (oe[i].first == oe[i].second) {
            cuts.pb(abs(a[i] - a[i + 1]));
        }
    }

    sort(cuts.begin(), cuts.end());

    int cnt = 0;
    for (int i = 0; i < cuts.size(); i++) {
        if (b - cuts[i] >= 0) {
            b -= cuts[i];
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}
