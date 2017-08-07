/* graph : sssp (unweighted graph) */

#include <climits>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

int nr[] = {-1, 0, 1, 0};
int nc[] = {0, 1, 0, -1};

int main()
{
    int m, n, sr, sc, dr, dc;
    int grid[50][50];
    string dir;

    while (cin >> m >> n) {
        if (m == 0 && n == 0) {
            break;
        }

        memset(grid, 0, sizeof(grid));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        cin >> sr >> sc >> dr >> dc >> dir;

        sc--;
        sr--;
        dc--;
        dr--;

        vvi store(m - 1, vi(n - 1, 0));

        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n - 1; j++) {
                store[i][j] = grid[i][j] || grid[i + 1][j] || grid[i][j + 1] ||
                              grid[i + 1][j + 1];
            }
        }

        /* for (int i = 0; i < m - 1; i++) { */
        /*     for (int j = 0; j < n - 1; j++) { */
        /*         cout << store[i][j] << "  "; */
        /*     } */

        /*     cout << '\n'; */
        /* } */

        /* cout << '\n'; */

        if (store[sr][sc] || store[dr][dc]) {
            cout << -1 << '\n';
            continue;
        }

        vector<vvi> dist(m - 1, vvi(n - 1, vi(4, INT_MAX)));
        vector<vvi> vis(m - 1, vvi(n - 1, vi(4, 0)));

        int dirNum = 0;

        if (dir == "north") {
            dirNum = 0;
        } else if (dir == "east") {
            dirNum = 1;
        } else if (dir == "south") {
            dirNum = 2;
        } else if (dir == "west") {
            dirNum = 3;
        }

        dist[sr][sc][dirNum] = 0;
        vis[sr][sc][dirNum] = 1;

        queue<pair<int, ii>> q;
        q.push(pair<int, ii>(dirNum, ii(sr, sc)));

        while (!q.empty()) {
            pair<int, ii> u = q.front();
            q.pop();

            // push nearest dirs of u
            for (int i = 1; i < 4; i += 2) {
                pair<int, ii> v = pair<int, ii>(
                    (u.first + i) % 4, ii(u.second.first, u.second.second));

                if (!vis[v.second.first][v.second.second][v.first]) {
                    dist[v.second.first][v.second.second][v.first] =
                        dist[u.second.first][u.second.second][u.first] + 1;

                    q.push(v);

                    vis[v.second.first][v.second.second][v.first] = 1;
                }
            }

            // for range 1 - 3
            for (int k = 1; k <= 3; k++) {
                pair<int, ii> v = pair<int, ii>(
                    u.first, ii(u.second.first + (k * nr[u.first]),
                                u.second.second + (k * nc[u.first])));

                if (v.second.first < 0 || v.second.first >= m - 1 ||
                    v.second.second < 0 || v.second.second >= n - 1) {
                    break; // the neighbor is out of map
                }

                if (store[v.second.first][v.second.second]) {
                    break; // the neighbour is an obstacle
                }

                if (!vis[v.second.first][v.second.second][v.first]) {
                    dist[v.second.first][v.second.second][v.first] =
                        dist[u.second.first][u.second.second][u.first] + 1;

                    q.push(v);

                    vis[v.second.first][v.second.second][v.first] = 1;
                }
            }
        }

        /* for (int k = 0; k < 4; k++) { */
        /*   if (k == 0) { */
        /*     cout << "north:\n"; */
        /*   } else if (k == 1) { */
        /*     cout << "east:\n"; */
        /*   } else if (k == 2) { */
        /*     cout << "south:\n"; */
        /*   } else { */
        /*     cout << "west:\n"; */
        /*   } */

        /*   for (int i = 0; i < m - 1; i++) { */
        /*     for (int j = 0; j < n - 1; j++) { */
        /*       if (dist[i][j][k] == INT_MAX) { */
        /*         cout << "-  "; */
        /*       } else if (dist[i][j][k] <= 9) { */
        /*         cout << dist[i][j][k] << "  "; */
        /*       } else { */
        /*         cout << dist[i][j][k] << ' '; */
        /*       } */
        /*     } */

        /*     cout << '\n'; */
        /*   } */

        /*   cout << '\n'; */
        /* } */

        int result = dist[dr][dc][0];

        for (int i = 1; i < 4; i++) {
            result = min(result, dist[dr][dc][i]);
        }

        if (result == INT_MAX) {
            cout << -1 << '\n';
        } else {
            cout << result << '\n';
        }
    }
}
