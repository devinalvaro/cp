/* dp : 2d range sum */

#include <climits>
#include <iostream>
using namespace std;

int main()
{
    int n, arr[150][150];
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];

            if (i > 0) {
                arr[i][j] += arr[i - 1][j];
            }

            if (j > 0) {
                arr[i][j] += arr[i][j - 1];
            }

            if (i > 0 && j > 0) {
                arr[i][j] -= arr[i - 1][j - 1];
            }
        }
    }

    int ans = INT_MIN, sum;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = i; k < n; k++) {
                for (int l = j; l < n; l++) {
                    sum = arr[k][l];

                    if (i > 0) {
                        sum -= arr[i - 1][l];
                    }

                    if (j > 0) {
                        sum -= arr[k][j - 1];
                    }

                    if (i > 0 && j > 0) {
                        sum += arr[i - 1][j - 1];
                    }

                    ans = max(ans, sum);
                }
            }
        }
    }

    cout << ans << '\n';
}
