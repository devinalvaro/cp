#include <bits/stdc++.h>

using namespace std;

#define fi  first
#define se  second
#define pb  push_back
#define ll  long long
#define ve  vector
#define pq  priority_queue
#define um  unordered_map
#define us  unordered_set
#define pii pair<int, int>
#define pll pair<ll, ll>

#define ceil(x, y) (x + y - 1) / y
#define spnl(i, n) " \n"[(i == n - 1)]

int main() {
    ll n, m, k, l;
    scanf("%lld %lld %lld %lld", &n, &m, &k, &l);

    ll ans = ceil(l + k, m);

    if ((ans * m) > n) {
        puts("-1");
        return 0;
    }

    cout << ans << endl;

    return 0;
}
