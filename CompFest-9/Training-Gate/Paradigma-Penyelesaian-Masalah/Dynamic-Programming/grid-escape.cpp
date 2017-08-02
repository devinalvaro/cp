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

const int MOD = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(0);

    int r, c, n;
    cin >> r >> c >> n;

    vector<vector<int>> maze(r, vector<int>(c));
    maze[0][0] = 1;
    for (int i = 0; i < n; i++) {
        int b, k;
        cin >> b >> k;

        maze[b - 1][k - 1] = -1;
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (maze[i][j] == -1)
                continue;

            if (i > 0 && maze[i - 1][j] != -1) {
                maze[i][j] += (maze[i - 1][j] % MOD);
                maze[i][j] %= MOD;
            }
            if (j > 0 && maze[i][j - 1] != -1) {
                maze[i][j] += (maze[i][j - 1] % MOD);
                maze[i][j] %= MOD;
            }
        }
    }

    cout << (maze[r - 1][c - 1] == -1 ? 0 : maze[r - 1][c - 1] % MOD) << '\n';
}
