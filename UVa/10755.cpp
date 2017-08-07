/* dp : 1d range sum */
#include <climits>
#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    int tc, t;
    long long cube[21][21][21];
    cin >> tc;
    t = tc;

    while (t--) {
        if (t < tc - 1) {
            cout << '\n';
        }

        memset(cube, 0, sizeof(cube));
        int a, b, c;
        cin >> a >> b >> c;
        int i, j, k, l, m;

        for (i = 0; i < a; i++)
            for (j = 0; j < b; j++)
                for (k = 0; k < c; k++) {
                    cin >> cube[i][j][k];
                }

        for (k = 0; k < c; k++) {
            for (i = 0; i < a; i++) {
                for (j = 0; j < b; j++) {
                    if (i > 0) {
                        cube[i][j][k] += cube[i - 1][j][k];
                    }

                    if (j > 0) {
                        cube[i][j][k] += cube[i][j - 1][k];
                    }

                    if (i > 0 && j > 0) {
                        cube[i][j][k] -= cube[i - 1][j - 1][k];
                    }
                }
            }
        }

        long long max_all = INT_MIN, max_here, sum;

        for (i = 0; i < a; i++) {
            for (j = 0; j < b; j++) {
                for (l = i; l < a; l++) {
                    for (m = j; m < b; m++) {
                        max_here = 0;

                        for (k = 0; k < c; k++) {
                            sum = cube[l][m][k];

                            if (i > 0) {
                                sum -= cube[i - 1][m][k];
                            }

                            if (j > 0) {
                                sum -= cube[l][j - 1][k];
                            }

                            if (i > 0 && j > 0) {
                                sum += cube[i - 1][j - 1][k];
                            }

                            max_here += sum;
                            max_all = max(max_all, max_here);

                            if (max_here < 0) {
                                max_here = 0;
                            }
                        }
                    }
                }
            }
        }

        cout << max_all << "\n";
    }
}
