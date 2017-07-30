/* dp : 2d range sum */

#include <climits>
#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int tc, n, m;
    long long p, plot[101][101];
    cin >> tc;

    for (int t = 0; t < tc; t++) {
        memset(plot, INT_MAX, sizeof(plot));
        cin >> n >> m >> p;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> plot[i][j];

                if (i > 0) {
                    plot[i][j] += plot[i - 1][j];
                }

                if (j > 0) {
                    plot[i][j] += plot[i][j - 1];
                }

                if (i > 0 && j > 0) {
                    plot[i][j] -= plot[i - 1][j - 1];
                }
            }
        }

        long long price, min_price = INT_MAX;
        int area, max_area = INT_MIN;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = i; k < n; k++) {
                    for (int l = j; l < m; l++) {
                        price = plot[k][l];

                        if (i > 0) {
                            price -= plot[i - 1][l];
                        }

                        if (j > 0) {
                            price -= plot[k][j - 1];
                        }

                        if (i > 0 && j > 0) {
                            price += plot[i - 1][j - 1];
                        }

                        area = (k - i + 1) * (l - j + 1);

                        if (price <= p && area > max_area) {
                            max_area = area;
                            min_price = price;
                        }

                        if (price <= p && area == max_area
                            && price < min_price) {
                            min_price = price;
                        }
                    }
                }
            }
        }

        if (min_price == INT_MAX) {
            min_price = 0;
        }

        if (max_area == INT_MIN) {
            max_area = 0;
        }

        cout << "Case #" << t + 1 << ": " << max_area << ' ' << min_price
             << '\n';
    }
}
