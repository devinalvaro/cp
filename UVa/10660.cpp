/* brute force : iterative */

#include <climits>
#include <cmath>
#include <iostream>
using namespace std;

int coor[25][2];

int dist(int a, int b)
{
    return abs(coor[a][0] - coor[b][0]) + abs(coor[a][1] - coor[b][1]);
}

int main()
{
    int t, n, x, y, ans[5], city[25], town[5][5];
    int k = 0;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            coor[k][0] = i;
            coor[k][1] = j;
            k++;
        }
    }

    cin >> t;

    while (t--) {
        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 5; j++) {
                town[i][j] = 0;
            }

        for (int i = 0; i < 25; i++) {
            city[i] = 0;
        }

        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> x >> y;
            cin >> town[x][y];
        }

        int k = 0;

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                city[k++] = town[i][j];
            }
        }

        int sum_all = INT_MAX;

        for (int i = 0; i < 21; i++) {
            for (int j = i + 1; j < 22; j++) {
                for (int k = j + 1; k < 23; k++) {
                    for (int l = k + 1; l < 24; l++) {
                        for (int m = l + 1; m < 25; m++) {
                            int sum = 0;

                            for (int a = 0; a < 25; a++) {
                                int local = INT_MAX;
                                local = min(local, (city[a] * dist(a, i)));
                                local = min(local, (city[a] * dist(a, j)));
                                local = min(local, (city[a] * dist(a, k)));
                                local = min(local, (city[a] * dist(a, l)));
                                local = min(local, (city[a] * dist(a, m)));
                                sum += local;
                            }

                            if (sum < sum_all) {
                                sum_all = sum;
                                ans[0] = i;
                                ans[1] = j;
                                ans[2] = k;
                                ans[3] = l;
                                ans[4] = m;
                            }
                        }
                    }
                }
            }
        }

        cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << ' ' << ans[3] << ' '
             << ans[4] << '\n';
    }
}
