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
    int n, k;
    cin >> n >> k;

    ve<double> a(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        a[i] += a[i - 1];
    }

    double heat = DBL_MIN;
    for (int j = k; j <= n; j++) {
        for (int i = 1; i + j - 1 <= n; i++) {
            double avg = (a[i + j - 1] - a[i - 1]) / j;
            heat = max(heat, avg);
        }
    }
    cout << fixed << setprecision(12) << heat << endl;

    return 0;
}
