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
    int n, m;
    cin >> n >> m;

    ll hi = 0, lo = 0;
    for (int i = 0; i < n; i++) {
        hi += abs(i);
        lo += abs(i - (n / 2));
    }

    ll sum = 0;
    for (int i = 0; i < m; i++) {
        int x, d;
        cin >> x >> d;

        if (d < 0) {
            sum += (d * lo) + (x * n);
        } else {
            sum += (d * hi) + (x * n);
        }
    }
    cout << fixed << setprecision(12) << 1.0 * sum / n << endl;

    return 0;
}
