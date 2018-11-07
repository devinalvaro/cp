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

const int MOD = 998244353;

int mod(long long n) {
    return (n % MOD + MOD) % MOD;
}

int add(long long a, long long b) {
    return mod(a + b);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    string s, t;
    cin >> s >> t;

    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());

    int pwr = 1, cur = 0, ans = 0;
    for (int i = 0; i < m; i++) {
        if (i < n && s[i] == '1') {
            cur = add(cur, pwr);
        }
        if (t[i] == '1') {
            ans = add(ans, cur);
        }
        pwr = add(pwr, pwr);
    }
    printf("%d\n", ans);

    return 0;
}
