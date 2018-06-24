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
    ll l, r, x, y;
    cin >> l >> r >> x >> y;

    if (y % x != 0) {
        puts("0");
        return 0;
    }

    y /= x;

    us<int> s;
    for (ll i = 1; i <= sqrt(y); i++) {
        if (y % i != 0) {
            continue;
        }

        ll j = y / i;
        if (i * x >= l && i * x <= r && j * x >= l && j * x <= r &&
            __gcd(i, j) == 1) {
            s.insert(i);
            s.insert(j);
        }
    }

    cout << s.size() << endl;

    return 0;
}
