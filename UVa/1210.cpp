/* dp : knapsack */

#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

vector<int> primes;

void sieve(int n)
{
    bool isPrime[1121];

    for (int i = 2; i <= n; i++)
        isPrime[i] = 1;

    for (int i = 2; i <= n;) {
        primes.push_back(i);

        for (int j = 2 * i; j <= n; j += i)
            isPrime[j] = 0;

        while (!isPrime[++i])
            ;
    }
}

int main()
{
    sieve(1120);

    int dp[1121][15];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;

    for (int p = 0; p < (int)primes.size(); p++)
        for (int i = 1120; i >= primes[p]; i--)
            for (int j = 1; j <= 14; j++)
                dp[i][j] += dp[i - primes[p]][j - 1];

    int n, k;

    while (cin >> n >> k) {
        if (n == 0 && k == 0)
            break;

        cout << dp[n][k] << '\n';
    }
}
