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

const int N = 1e5;

int main() {
    int n;
    scanf("%d", &n);

    vec<int> cnt(N + 1, 0);
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);

        cnt[a]++;
    }

    ll ans = 0;

    vec<ll> dp(N + 1);
    dp[1] = cnt[1];

    for (int i = 2; i <= N; i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + (1LL * cnt[i] * i));
        ans = max(ans, dp[i]);
    }

    printf("%lld\n", ans);

    return 0;
}
