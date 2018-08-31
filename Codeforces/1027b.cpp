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

ll cl(ll x, ll y) {
    return (x + y - 1) / y;
}

ll dv(ll x, ll y, bool half) {
    ll d = x * (y - 1);

    if (half) {
        return d / 2;
    }
    return cl(d, 2);
}

int main() {
    int n, q;
    cin >> n >> q;

    while (q--) {
        int i, j;
        cin >> i >> j;

        bool half = (n & 1) && !(i & 1) && (j & 1);

        ll sum = dv(n, i, half) + cl(j, 2);
        if (i + j & 1) {
            sum += cl(1LL * n * n, 2);
        }
        cout << sum << endl;
    }

    return 0;
}
