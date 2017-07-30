/* dp : coin change */

#include <algorithm>
#include <climits>
#include <iostream>
#include <string.h>
using namespace std;

int p, n, bill[110], memo[10100];

int main()
{
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;

    while (t--) {
        cin >> p >> n;

        for (int i = 0; i < n; i++) {
            cin >> bill[i];
        }

        for (int i = 0; i < 10100; i++) {
            memo[i] = INT_MAX;
        }

        memo[0] = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 10000; j >= 0; j--) {
                if (memo[j] != INT_MAX && j + bill[i] <= 10000
                    && memo[j] + 1 < memo[j + bill[i]]) {
                    memo[j + bill[i]] = memo[j] + 1;
                }
            }
        }

        for (int i = p; i <= 10000; i++) {
            if (memo[i] != INT_MAX) {
                cout << i << ' ' << memo[i] << '\n';
                break;
            }
        }
    }
}
