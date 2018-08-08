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

    int xa = 0, xb = 0;
    ve<int> a(n), b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        xa ^= a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        xb ^= b[i];
    }

    if (xa != xb) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";

    cout << (a[0] ^ (xb ^ b[0]));
    for (int i = 1; i < m; i++) {
        cout << " " << b[i];
    }
    cout << endl;

    for (int i = 1; i < n; i++) {
        cout << a[i];
        for (int j = 1; j < m; j++) {
            cout << " 0";
        }
        cout << endl;
    }

    return 0;
}
