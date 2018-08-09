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

    ve<ve<ll>> a(2, ve<ll>(n));
    for (int i = 0; i < n; i++) {
        cin >> a[0][i];
    }
    for (int i = 0; i < n; i++) {
        cin >> a[1][i];
    }

    ve<ve<ll>> asc(2, ve<ll>(n + 1)), dsc(2, ve<ll>(n + 1)), sum(2, ve<ll>(n + 1));
    for (int i = n - 1, k = 0; i >= 0; i--, k++) {
        asc[0][i] = asc[0][i + 1] + (i * a[0][i]);
        asc[1][i] = asc[1][i + 1] + (i * a[1][i]);

        dsc[0][i] = dsc[0][i + 1] + (k * a[0][i]);
        dsc[1][i] = dsc[1][i + 1] + (k * a[1][i]);

        sum[0][i] = sum[0][i + 1] + a[0][i];
        sum[1][i] = sum[1][i + 1] + a[1][i];
    }

    ll best = 0, cnt = 0;
    for (int i = 0, j = 0; i < n; i++, j^=1) {
        ll test = cnt;
        test += asc[j][i] + (i * sum[j][i]);
        test += dsc[j ^ 1][i] + ((i + n) * sum[j ^ 1][i]);
        best = max(best, test);

        cnt += (2 * i) * a[j][i];
        cnt += (2 * i + 1) * a[j ^ 1][i];
    }
    cout << best << endl;

    return 0;
}
