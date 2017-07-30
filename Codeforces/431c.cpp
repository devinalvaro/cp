#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

const int MOD = 1000000007;

int main()
{
    int n, k, d;
    cin >> n >> k >> d;

    vector<vector<long long>> dp(n + 1, vector<long long>(2));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= min(d - 1, i); j++) {
            dp[i][0] += (dp[i - j][0] % MOD);
            dp[i][1] += (dp[i - j][1] % MOD);

            dp[i][0] %= MOD;
            dp[i][1] %= MOD;
        }
        for (int j = d; j <= min(k, i); j++) {
            dp[i][1] += ((dp[i - j][0] % MOD) + (dp[i - j][1] % MOD));

            dp[i][1] %= MOD;
        }
    }

    /* for (int i = 1; i <= n; i++) { */
    /*     cout << dp[i][0] << ' ' << dp[i][1] << endl; */
    /* } */

    cout << dp[n][1] << endl;
}
