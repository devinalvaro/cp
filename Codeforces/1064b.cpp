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
        int a;
        scanf("%d", &a);

        int cnt = 0;
        for (int i = 0; i < 31; i++) {
            cnt += (true && (a & (1 << i)));
        }
        printf("%d\n", (int)pow(2, cnt));
    }

    return 0;
}
