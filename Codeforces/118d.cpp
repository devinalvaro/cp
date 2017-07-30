#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

const long long MOD = 100000000;

int main()
{
    ios_base::sync_with_stdio(0);

    long long n1, n2, k1, k2;
    cin >> n1 >> n2 >> k1 >> k2;

    vector<vector<vector<long long>>> ways(
        n1 + 1, vector<vector<long long>>(n2 + 1, vector<long long>(2)));
    ways[0][0][0] = 1;
    ways[0][0][1] = 1;

    for (long long i = 0; i <= n1; i++) {
        for (long long j = 0; j <= n2; j++) {
            for (long long u = 1; u <= min(k1, (i)); u++) {
                ways[i][j][0] += (ways[i - u][j][1] % MOD);
            }
            for (long long u = 1; u <= min(k2, (j)); u++) {
                ways[i][j][1] += (ways[i][j - u][0] % MOD);
            }

            ways[i][j][0] %= MOD;
            ways[i][j][1] %= MOD;
        }
    }

    cout << (ways[n1][n2][0] + ways[n1][n2][1]) % MOD << '\n';
}
