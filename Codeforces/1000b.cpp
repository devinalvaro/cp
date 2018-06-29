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
    ll m;
    cin >> n >> m;

    ve<int> a(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    a[n + 1] = m;

    ve<ll> lits(n + 2);
    for (int i = 1; i <= n + 1; i++) {
        lits[i] = lits[i - 1];
        if (i & 1) {
            lits[i] += a[i] - a[i - 1];
        }
    }

    ll maxLit = lits[n + 1];

    ll lit = 0, dim = 0;
    for (int i = n; i >= 0; i--) {
        ll dur = a[i + 1] - a[i];
        if (i & 1) {
            lit += dur;
        } else {
            dim += dur;
        }

        ll currentLit = lits[i] + lit - 1;
        if (currentLit > maxLit) {
            maxLit = currentLit;
        }
    }

    cout << maxLit << endl;

    return 0;
}
