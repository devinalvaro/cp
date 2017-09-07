#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    vector<vector<char>> grid(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int startX, startY, endX, endY;
    cin >> startX >> startY >> endX >> endY;

    vector<vector<int>> dist(n, vector<int>(n, -1));
    dist[startX][startY] = 0;

    queue<pair<int, int>> squares;
    squares.push(make_pair(startX, startY));

    while (!squares.empty()) {
        int x = squares.front().first;
        int y = squares.front().second;
        squares.pop();

        for (int j = y - 1; j >= 0; j--) {
            if (grid[x][j] == 'X')
                break;

            if (dist[x][j] == -1) {
                dist[x][j] = dist[x][y] + 1;

                squares.push(make_pair(x, j));
            }
        }
        for (int j = y + 1; j < n; j++) {
            if (grid[x][j] == 'X')
                break;

            if (dist[x][j] == -1) {
                dist[x][j] = dist[x][y] + 1;

                squares.push(make_pair(x, j));
            }
        }

        for (int i = x - 1; i >= 0; i--) {
            if (grid[i][y] == 'X')
                break;

            if (dist[i][y] == -1) {
                dist[i][y] = dist[x][y] + 1;

                squares.push(make_pair(i, y));
            }
        }
        for (int i = x + 1; i < n; i++) {
            if (grid[i][y] == 'X')
                break;

            if (dist[i][y] == -1) {
                dist[i][y] = dist[x][y] + 1;

                squares.push(make_pair(i, y));
            }
        }
    }

    cout << dist[endX][endY] << '\n';
}
