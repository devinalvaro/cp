/* dp : knapsack */

#include <iostream>
#include <string.h>
using namespace std;

int n, q, d, m;
long long arr[210], dp[210][11][21];

long long process(int i, int cnt, int sum)
{
    if (cnt == m) {
        if (sum == 0) {
            return 1;
        } else {
            return 0;
        }
    }

    if (i >= n) {
        return 0;
    }

    if (dp[i][cnt][sum] != -1) {
        return dp[i][cnt][sum];
    }

    long long temp = (sum + arr[i]) % d;

    if (temp < 0) {
        temp += d;
    }

    return dp[i][cnt][sum]
        = process(i + 1, cnt + 1, temp) + process(i + 1, cnt, sum % d);
}

int main()
{
    int tc = 1;
    cin >> n >> q;

    while (n != 0 && q != 0) {
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        cout << "SET " << tc++ << ":\n";

        for (int i = 0; i < q; i++) {
            memset(dp, -1, sizeof(dp));
            cin >> d >> m;
            cout << "QUERY " << i + 1 << ": " << process(0, 0, 0) << '\n';
        }

        cin >> n >> q;
    }
}
