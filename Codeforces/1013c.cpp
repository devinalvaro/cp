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

    ve<int> a(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int lower_mid = n - 1, upper_mid = n;
    ll best = 1LL * (a[lower_mid] - a[0]) * (a[(2 * n) - 1] - a[upper_mid]);

    for (int i = 1; i + n - 1 <= (2 * n) - 1; i++) {
        best = min(best, 1LL * (a[(2 * n) - 1] - a[0]) * (a[i + n - 1] - a[i]));
    }

    cout << best << endl;

    return 0;
}
