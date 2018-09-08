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

int main()
{
    ios_base::sync_with_stdio(0);

    int r, c;
    cin >> r >> c;

    vector<vector<char>> grid(r, vector<char>(c));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> dist(r, vector<int>(c, -1));
    dist[0][0] = 0;

    queue<pair<int, int>> q;
    q.push(pair<int, int>(0, 0));
    while (!q.empty()) {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();

        if (i > 0 && grid[i - 1][j] == '.') {
            dist[i - 1][j] = dist[i][j] + 1;
            grid[i - 1][j] = '_';

            q.push(pair<int, int>(i - 1, j));
        }
        if (j > 0 && grid[i][j - 1] == '.') {
            dist[i][j - 1] = dist[i][j] + 1;
            grid[i][j - 1] = '_';

            q.push(pair<int, int>(i, j - 1));
        }
        if (i < r - 1 && grid[i + 1][j] == '.') {
            dist[i + 1][j] = dist[i][j] + 1;
            grid[i + 1][j] = '_';

            q.push(pair<int, int>(i + 1, j));
        }
        if (j < c - 1 && grid[i][j + 1] == '.') {
            dist[i][j + 1] = dist[i][j] + 1;
            grid[i][j + 1] = '_';

            q.push(pair<int, int>(i, j + 1));
        }
    }

    cout << dist[r - 1][c - 1] << '\n';
}
