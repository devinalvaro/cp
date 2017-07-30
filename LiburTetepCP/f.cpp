#include <climits>
#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

int dir[] = { -1, 0, 1 };

float distance(int a, int b, int i, int j)
{
    return sqrt(((a - i) * (a - i)) + ((b - j) * (b - j)));
}

int main()
{
    int r, c, m, n, x, y, l;

    while (true) {
        cin >> r >> c;
        if (r == 0 && c == 0) {
            break;
        }

        int forest[r + 1][c + 1];
        int dist[r + 1][c + 1];
        memset(forest, 0, sizeof(forest));
        for (int i = 0; i < r + 1; i++) {
            for (int j = 0; j < c + 1; j++) {
                dist[i][j] = INT_MAX;
            }
        }
        dist[1][1] = 0;

        cin >> m;
        for (int i = 0; i < m; i++) {
            cin >> x >> y;
            forest[x][y] = -1;
        }
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> x >> y >> l;

            for (int i = 1; i <= r; i++) {
                for (int j = 1; j <= c; j++) {
                    if (distance(i, j, x, y) <= (float)l)
                        forest[i][j] = -1;
                }
            }
        }

        /*         for (int i = 1; i < r + 1; i++) { */
        /*             for (int j = 1; j < c + 1; j++) { */
        /*                 if (forest[i][j] == -1) */
        /*                     cout << "x "; */
        /*                 else */
        /*                     cout << forest[i][j] << ' '; */
        /*             } */
        /*             cout << endl; */
        /*         } */
        /*         cout << endl; */

        queue<pair<int, int>> q;
        q.push(pair<int, int>(1, 1));
        while (!q.empty()) {
            pair<int, int> u = q.front();
            q.pop();

            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    pair<int, int> v(u.first + dir[i], u.second + dir[j]);

                    if (dir[i] != 0 && dir[j] != 0)
                        continue;
                    if (v.first <= 0 || v.first > r)
                        continue;
                    if (v.second <= 0 || v.second > c)
                        continue;
                    if (forest[v.first][v.second] == -1)
                        continue;

                    /* cout << v.first << ' ' << v.second << endl; */

                    if (dist[v.first][v.second] == INT_MAX) {
                        dist[v.first][v.second] = dist[u.first][u.second] + 1;
                        q.push(v);
                    }
                }
            }
        }

        /*         for (int i = 1; i < r + 1; i++) { */
        /*             for (int j = 1; j < c + 1; j++) { */
        /*                 if (dist[i][j] == INT_MAX) { */
        /*                     cout << "x "; */
        /*                 } else { */
        /*                     cout << dist[i][j] << ' '; */
        /*                 } */
        /*             } */
        /*             cout << endl; */
        /*         } */

        if (dist[r][c] == INT_MAX) {
            cout << "Impossible." << endl;
        } else {
            cout << dist[r][c] << endl;
        }
    }
}
