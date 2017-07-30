/* dp : non classical */

#include <cstring>
#include <iostream>
using namespace std;

int main()
{
    int n, k, m;
    long long memo[60][60];

    while (cin >> n >> k >> m) {
        memset(memo, 0, sizeof(memo));
        memo[0][0] = 1;

        for (int j = 1; j <= k; j++) {
            for (int i = 1; i <= n; i++) {
                for (int l = 1; l <= m; l++) {
                    if (i - l >= 0) {
                        memo[i][j] += memo[i - l][j - 1];
                    }
                }
            }
        }

        cout << memo[n][k] << '\n';
    }
}
