#include <bits/stdc++.h>

using namespace std;

int di[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dj[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int i, int j,
        const int n, const int m)
{
    visited[i][j] = true;

    int size = 1;

    for (int k = 0; k < 8; k++) {
        int r = i + di[k];
        int c = j + dj[k];

        if (r >= 0 && r < n && c >= 0 && c < m && grid[r][c] &&
            !visited[r][c]) {
            size += dfs(grid, visited, r, c, n, m);
        }
    }

    return size;
}

int main()
{
    ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));

    int largestSize = INT_MIN;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!grid[i][j] || visited[i][j])
                continue;

            largestSize = max(largestSize, dfs(grid, visited, i, j, n, m));
        }
    }

    cout << largestSize << '\n';
}
