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
    ve<int> s(3);
    for (int i = 0; i < 3; i++) {
        scanf("%d", &s[i]);
    }
    sort(s.begin(), s.end());

    printf("%d\n", max(0, s[2] - (s[0] + s[1]) + 1));

    return 0;
}
