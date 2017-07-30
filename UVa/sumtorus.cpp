/* dp : 2d range sum */

#include <climits>
#include <iostream>
using namespace std;

int main()
{
    int t, n;
    int square[75][75], torus[150][150];

    cin >> t;

    while (t--) {
        cin >> n;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> square[i][j];
            }
        }

        /* for (int i = 0; i < n; i++) { */
        /*   for (int j = 0; j < n; j++) { */
        /*     cout << square[i][j] << ' '; */
        /*   } */

        /*   cout << '\n'; */
        /* } */

        for (int k = 0; k < 2 * n; k += n) {
            for (int l = 0; l < 2 * n; l += n) {
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        torus[k + i][l + j] = square[i][j];
                    }
                }
            }
        }

        /* for (int i = 0; i < 2 * n; i++) { */
        /*   for (int j = 0; j < 2 * n; j++) { */
        /*     cout << torus[i][j] << ' '; */
        /*   } */

        /*   cout << '\n'; */
        /* } */

        for (int i = 0; i < 2 * n; i++) {
            for (int j = 0; j < 2 * n; j++) {
                if (i > 0)
                    torus[i][j] += torus[i - 1][j];

                if (j > 0)
                    torus[i][j] += torus[i][j - 1];

                if (i > 0 && j > 0)
                    torus[i][j] -= torus[i - 1][j - 1];
            }
        }

        int sum, maxSum = INT_MIN;

        for (int k = 0; k < n; k++) {
            for (int l = 0; l < n; l++) {
                for (int i = k; i < k + n && i < 2 * n; i++) {
                    for (int j = l; j < l + n && j < 2 * n; j++) {
                        sum = torus[i][j];

                        if (k > 0)
                            sum -= torus[k - 1][j];

                        if (l > 0)
                            sum -= torus[i][l - 1];

                        if (k > 0 && l > 0)
                            sum += torus[k - 1][l - 1];

                        maxSum = max(maxSum, sum);
                    }
                }
            }
        }

        cout << maxSum << '\n';
    }
}
