/* dp : coin change */

#include <climits>
#include <iostream>
#include <string.h>
using namespace std;

int M, C, price[25][25], memo[210][25];

int shop(int money, int g)
{
    if (money < 0) {
        return INT_MIN;
    }

    if (g == C) {
        return M - money; // actual money spent
    }

    if (memo[money][g] != -1) {
        return memo[money][g];
    }

    int ans = -1;

    for (int i = 1; i <= price[g][0]; i++) {
        ans = max(ans, shop(money - price[g][i], g + 1));
    }

    return memo[money][g] = ans;
}

int main()
{
    int t, score;
    cin >> t;

    while (t--) {
        cin >> M >> C;

        for (int i = 0; i < C; i++) {
            cin >> price[i][0]; // store K in price[i][0]

            for (int j = 1; j <= price[i][0]; j++) {
                cin >> price[i][j]; // cin price of each model
            }
        }

        memset(memo, -1, sizeof memo);
        score = shop(M, 0);

        if (score < 0) {
            cout << "no solution\n";
        } else {
            cout << score << '\n';
        }
    }
}
