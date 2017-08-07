/* dp : non-classical */

#include <climits>
#include <cstring>
#include <iostream>
using namespace std;

int main()
{
    int l, n;

    while (cin >> l) {
        if (l == 0)
            break;

        cin >> n;

        int c[n + 2];

        c[0] = 0;

        for (int i = 1; i <= n; i++) {
            cin >> c[i];
        }

        c[n + 1] = l;

        int dp[n + 2][n + 2];

        for (int i = 0; i < n + 2; i++) {
            for (int j = 0; j < n + 2; j++) {
                dp[i][j] = 10e8;
            }
        }

        for (int i = 0; i < n + 1; i++) {
            dp[i][i + 1] = 0;
        }

        for (int gap = 2; gap < n + 2; gap++) {
            for (int i = 0; i + gap < n + 2; i++) {
                int j = i + gap;

                for (int k = i + 1; k < j; k++) {
                    /*   cout << "i: " << i << " k: " << k << " j: " << j <<
                     * '\n';
                     */
                    /*   cout << "dp[i][j]: " << dp[i][j] << '\n'; */
                    /*   cout << "c[j] - c[i] = " << c[j] << " - " << c[i]; */
                    /*   cout << " = " << c[j] - c[i] << '\n'; */

                    dp[i][j] =
                        min(dp[i][j], dp[i][k] + dp[k][j] + (c[j] - c[i]));

                    /* cout << "dp[i][j]: " << dp[i][j] << "\n\n"; */
                }
            }
        }

        /* for (int i = 0; i < n + 2; i++) { */
        /*   for (int j = 0; j < n + 2; j++) { */
        /*     cout << dp[i][j] << ' '; */
        /*   } */

        /*   cout << '\n'; */
        /* } */

        cout << "The minimum cutting is " << dp[0][n + 1] << ".\n";
    }
}
