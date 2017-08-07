/* dp : non classical */

#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        x /= 100;

        vector<vector<int>> winds(10, vector<int>(x));
        for (int i = 9; i >= 0; i--) {
            for (int j = 0; j < x; j++) {
                cin >> winds[i][j];
            }
        }

        vector<vector<int>> cost(10, vector<int>(x + 1, INT_MAX));
        cost[0][0] = 0;

        for (int j = 0; j < x; j++) {
            for (int i = 9; i >= 0; i--) {
                if (cost[i][j] == INT_MAX)
                    continue;

                if (i < 9)
                    cost[i + 1][j + 1] =
                        min(cost[i + 1][j + 1], cost[i][j] + 60 - winds[i][j]);
                if (i > 0)
                    cost[i - 1][j + 1] =
                        min(cost[i - 1][j + 1], cost[i][j] + 20 - winds[i][j]);
                cost[i][j + 1] =
                    min(cost[i][j + 1], cost[i][j] + 30 - winds[i][j]);
            }
        }

        cout << cost[0][x] << "\n\n";
    }
}
