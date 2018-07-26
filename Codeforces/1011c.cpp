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

int n;
double m;
int a[1000], b[1000];

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    double l = 0, r = 10e9;
    bool pass = false;

    for (int k = 0; k < 60; k++) {
        double mid = (l + r) / 2, fuel = mid;

        for (int i = 0; i < n; i++) {
            fuel -= (m + fuel) / a[i];
            if (fuel < 0) {
                break;
            }

            fuel -= (m + fuel) / b[i];
            if (fuel < 0) {
                break;
            }
        }

        if (fuel >= 0) {
            r = mid;
            pass = true;
        } else {
            l = mid;
        }
    }

    if (pass) {
        cout << fixed << setprecision(18) << r << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
