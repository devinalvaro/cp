/* dp : coin change */

#include <cstring>
#include <iostream>
using namespace std;

int main()
{
    int n;
    int coins[] = { 1, 5, 10, 25, 50 };
    long long dp[30003];

    memset(dp, 0, sizeof(dp));
    dp[0] = 1;

    for (int i = 0; i < 5; i++) {
        for (int j = coins[i]; j <= 30000; j++) {
            dp[j] += dp[j - coins[i]];
        }
    }

    while (cin >> n) {
        if (dp[n] == 1)
            cout << "There is only 1 way ";
        else
            cout << "There are " << dp[n] << " ways ";

        cout << "to produce " << n << " cents change.\n";
    }
}
