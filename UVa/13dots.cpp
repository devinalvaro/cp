/* dp : knapsack */

#include <algorithm>
#include <climits>
#include <iostream>
#include <string.h>
using namespace std;

int m, n, items[110][2], memo[110][11000];

int buy(int i, int spending)
{
    if (spending > m && m <= 1800) {
        return INT_MIN;
    }

    if (spending - 200 > m) {
        return INT_MIN;
    }

    if (i == n) {
        if (spending > m && spending <= 2000) {
            return INT_MIN;
        }

        return 0;
    }

    if (memo[i][spending] != -1) {
        return memo[i][spending];
    }

    return memo[i][spending] = max(buy(i + 1, spending),
               items[i][1] + buy(i + 1, spending + items[i][0]));
}

int main()
{
    while (cin >> m >> n) {
        for (int i = 0; i < n; i++) {
            cin >> items[i][0] >> items[i][1];
        }

        memset(memo, -1, sizeof(memo));
        cout << buy(0, 0) << '\n';
    }
}
