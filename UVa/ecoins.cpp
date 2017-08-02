/* dp : coin change */

#include <algorithm>
#include <climits>
#include <iostream>
#include <string.h>
using namespace std;

int coin[50][2], dp[320][320];

int main()
{
    int n, m, s;
    cin >> n;

    while (n--) {
        cin >> m >> s;

        for (int i = 0; i < m; i++) {
            cin >> coin[i][0] >> coin[i][1];
        }

        for (int i = 0; i < 320; i++)
            for (int j = 0; j < 320; j++) {
                dp[i][j] = INT_MAX;
            }

        dp[0][0] = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j <= 300; j++) {
                for (int k = 0; k <= 300; k++) {
                    if (dp[j][k] != INT_MAX && j + coin[i][0] <= 300 &&
                        k + coin[i][1] <= 300 &&
                        dp[j + coin[i][0]][k + coin[i][1]] > dp[j][k] + 1) {
                        dp[j + coin[i][0]][k + coin[i][1]] = dp[j][k] + 1;
                    }
                }
            }
        }

        int result = INT_MAX;

        for (int i = 0; i <= 300; i++) {
            for (int j = 0; j <= 300; j++) {
                if ((i * i) + (j * j) == (s * s)) {
                    result = min(result, dp[i][j]);
                }
            }
        }

        if (result == INT_MAX) {
            cout << "not possible\n";
        } else {
            cout << result << '\n';
        }
    }
}
