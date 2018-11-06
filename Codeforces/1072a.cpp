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
    int w, h, k;
    scanf("%d %d %d", &w, &h, &k);

    int cnt = 0;
    for (int i = 0; i < k; i++) {
        int a = w - (4 * i);
        int b = h - (4 * i);
        cnt += max(2 * (a + b) - 4, 0);
    }
    printf("%d\n", cnt);

    return 0;
}
