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

const int MOD = 1e9 + 7;

int mod(ll n) {
    return (n % MOD + MOD) % MOD;
}

int add(ll a, ll b) {
    return mod(a + b);
}

int sub(ll a, ll b) {
    return mod(a - b);
}

int mult(ll a, ll b) {
    if (b == 0) return 0;
    ll m = mult(a, b / 2);
    ll mm = add(m, m);
    return add(mm, (b & 1 ? a : 0));
}

int power(ll a, ll b) {
    if (b == 0) return 1;
    ll p = power(a, b / 2);
    ll pp = mult(p, p);
    return mult(pp, (b & 1 ? a : 1));
}

int main() {
    ll x, k;
    cin >> x >> k;

    if (x == 0) {
        cout << 0 << endl;
        return 0;
    }
    if (k == 0) {
        cout << mult(x, 2) << endl;
        return 0;
    }

    int p = power(2, k);
    int r = sub(mult(mult(p, 2), x), (p - 1));
    cout << r << endl;

    return 0;
}
