/* dp : non classical */

#include <cstring>
#include <iostream>
using namespace std;

int n, k, memo[110][110];

int main()
{
    cin >> n >> k;

    while (n != 0 || k != 0) {
        memset(memo, 0, sizeof(memo));

        for (int i = 1; i <= n; i++) {
            memo[i][1] = 1;
        }

        for (int c = 2; c <= k; c++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= i; j++) {
                    memo[i][c] += memo[j][c - 1];
                    memo[i][c] %= 1000000;
                }

                memo[i][c] += 1;
                memo[i][c] %= 1000000;
            }
        }

        cout << memo[n][k] % 1000000 << '\n';
        cin >> n >> k;
    }
}
