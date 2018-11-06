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
    int t;
    scanf("%d", &t);

    while (t--) {
        int L, v, l, r;
        scanf("%d %d %d %d", &L, &v, &l, &r);

        int cnt = (r / v) - ((l - 1) / v);
        printf("%d\n", (L / v) - cnt);
    }

    return 0;
}
