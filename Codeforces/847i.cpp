#include <bits/stdc++.h>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, -1, 0, 1};

void bfs(int i, int j, const vector<vector<char>> &grid,
         vector<vector<long long>> &noise, vector<vector<bool>> &visited,
         const long long &q, const int &n, const int &m)
{
    visited[i][j] = true;

    long long sound = ((long long)grid[i][j] - 64) * q;
    noise[i][j] += sound;

    queue<pair<pair<int, int>, int>> qu;
    qu.push(make_pair(make_pair(i, j), sound));

    while (!qu.empty()) {
        int ui = qu.front().first.first;
        int uj = qu.front().first.second;
        long long us = qu.front().second;

        qu.pop();

        if (us <= 0)
            continue;

        for (int k = 0; k < 4; k++) {
            int vi = ui + dr[k];
            int vj = uj + dc[k];
            long long vs = us / 2;

            if (vi >= 0 && vi < n && vj >= 0 && vj < m && grid[vi][vj] != '*' &&
                !visited[vi][vj]) {
                visited[vi][vj] = true;

                noise[vi][vj] += vs;

                qu.push(make_pair(make_pair(vi, vj), vs));
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);

    int n, m;
    long long q, p;
    cin >> n >> m >> q >> p;

    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<long long>> noise(n, vector<long long>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ((int)grid[i][j] >= 65 && (int)grid[i][j] <= 90) {
                vector<vector<bool>> visited(n, vector<bool>(m, false));

                bfs(i, j, grid, noise, visited, q, n, m);
            }
        }
    }

    int quarter = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            /* cout << noise[i][j] << (j == m - 1 ? '\n' : ' '); */

            if (noise[i][j] > p) {
                quarter++;
            }
        }
    }
    cout << quarter << '\n';
}
