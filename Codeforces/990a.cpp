#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ll long long
#define ve vector
#define um unordered_map
#define us unordered_set

int main() {
    ll n, m, a, b;
    cin >> n >> m >> a >> b;

    ll x = n % m;
    ll res = min((m - x) * a, x * b);

    cout << res << endl;

    return 0;
}
