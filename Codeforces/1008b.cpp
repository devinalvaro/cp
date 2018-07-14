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

    ve<int> w(n), h(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> h[i];
    }

    int last = max(w[0], h[0]);
    for (int i = 1; i < n; i++) {
        int m = max(w[i], h[i]), n = min(w[i], h[i]);
        if (m <= last) {
            last = m;
            continue;
        } else if (n <= last) {
            last = n;
            continue;
        } else {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";

    return 0;
}
