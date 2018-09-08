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

int n, m;
vector<vector<char>> tembok;
vector<vector<bool>> visited;

long long dfs(int r, int c)
{
    visited[r][c] = true;

    long long size = 1;
    if (r > 0 && tembok[r - 1][c] == '.' && !visited[r - 1][c]) {
        size += dfs(r - 1, c);
    }
    if (r < n - 1 && tembok[r + 1][c] == '.' && !visited[r + 1][c]) {
        size += dfs(r + 1, c);
    }
    if (c > 0 && tembok[r][c - 1] == '.' && !visited[r][c - 1]) {
        size += dfs(r, c - 1);
    }
    if (c < n - 1 && tembok[r][c + 1] == '.' && !visited[r][c + 1]) {
        size += dfs(r, c + 1);
    }
    return size;
}

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> n >> m;

    tembok.assign(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> tembok[i][j];
        }
    }

    visited.assign(n, vector<bool>(m, false));
    long long hole_count = 0, hole_size = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (tembok[i][j] == '.' && !visited[i][j]) {
                hole_count++;

                hole_size = max(hole_size, dfs(i, j));
            }
        }
    }

    cout << hole_count << ' ' << hole_size << '\n';
}
