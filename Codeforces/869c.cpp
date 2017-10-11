#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

int combin[5001][5001];
int fac[5001];

int countWays(int x, int y) {
    int result = 0;

    for (int i = 0; i <= min(x, y); i++) {
        int temp = fac[i];
        temp = (1LL * temp * combin[x][i]) % MOD;
        temp = (1LL * temp * combin[y][i]) % MOD;

        result = (result + temp) % MOD;
    }

    return result;
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    combin[0][0] = 1;
    for (int i = 1; i <= 5000; i++) {
        combin[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            combin[i][j] = ((long long)combin[i - 1][j] +
                            (long long)combin[i - 1][j - 1]) %
                           MOD;
        }
    }

    fac[0] = 1;
    for (int i = 1; i <= 5000; i++) {
        fac[i] = (1LL * i * fac[i - 1]) % MOD;
    }

    int result = 1;
    result = (1LL * result * countWays(a, b)) % MOD;
    result = (1LL * result * countWays(b, c)) % MOD;
    result = (1LL * result * countWays(c, a)) % MOD;
    cout << result << '\n';
}
