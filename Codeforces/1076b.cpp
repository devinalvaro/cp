#include <bits/stdc++.h>

using namespace std;

// clang-format off
#define ll  long long
#define fi  first
#define se  second
#define pb  push_back
#define us  unordered_set
#define um  unordered_map
#define pq  priority_queue
#define vec vector
#define pii pair<int, int>
#define pll pair<ll, ll>

#define ceil(x, y) ((x + y - 1) / y)
#define spnl(i, n) (i == n - 1 ? '\n' : ' ')

#define eps 1e-9
#define pi  acos(-1)
// clang-format on

int main() {
    ll n;
    scanf("%lld", &n);

    ll d = -1;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            d = i;
            break;
        }
    }

    if (d == -1) {
        printf("1\n");
    } else {
        if (n & 1) {
            n -= d;
        }
        printf("%lld\n", (d & 1 ? 1 : 0) + n / 2);
    }

    return 0;
}
