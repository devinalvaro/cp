#include <bits/stdc++.h>

using namespace std;

int main() {
    long long dp[50];
    dp[0] = 1;
    for (int i = 1; i < 50; i++) {
        dp[i] = (2LL * dp[i - 1]) + (1LL << (i - 1));
    }

    long long n;
    scanf("%lld", &n);
    n--;

    long long result = 0;
    for (int i = 0; i < 50; i++) {
        if (n & (1LL << i)) {
            result += dp[i];
        }
    }
    printf("%lld\n", result);

    return 0;
}
