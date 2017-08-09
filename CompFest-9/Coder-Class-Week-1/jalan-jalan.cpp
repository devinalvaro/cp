#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> d(n);
        for (int i = 0; i < n; i++) {
            cin >> d[i];
        }

        int S = accumulate(d.begin(), d.end(), 0);

        vector<vector<bool>> dp(n, vector<bool>(S + 1, false));
        dp[0][0] = true;
        dp[0][d[0]] = true;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= S; j++) {
                if (j >= d[i]) {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - d[i]];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        int max_x = 0;
        long long max_area = 0;

        for (int j = 0; j <= S; j++) {
            if (dp[n - 1][j]) {
                if ((long long)j * (long long)(S - j) > max_area) {
                    max_area = (long long)j * (long long)(S - j);

                    max_x = j;
                }
            }
        }

        cout << max_area << '\n';

        int i, j;
        stack<char> direction;

        for (i = n - 1, j = max_x; i > 0; i--) {
            if (j >= d[i] && dp[i - 1][j - d[i]]) {
                direction.push('R');

                j -= d[i];
            } else {
                direction.push('D');
            }
        }

        if (j == 0) {
            direction.push('D');
        } else {
            direction.push('R');
        }

        while (!direction.empty()) {
            cout << direction.top();

            direction.pop();
        }
        cout << '\n';
    }
}
