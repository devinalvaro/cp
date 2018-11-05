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
    ll b;
    scanf("%lld", &b);

    int cnt = 0;
    for (ll i = 1; i * i <= b; i++) {
        if (b % i == 0) {
            cnt += 2;
            if (i * i == b) {
                cnt -= 1;
            }
        }
    }

    printf("%d\n", cnt);

    return 0;
}
