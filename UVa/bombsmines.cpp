/* graph : sssp (unweighted graph) */

#include <climits>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    int r, c, br, bc, sr, sc, dr, dc, brn, n;
    int adjr[] = { 1, 0, -1, 0 }, adjc[] = { 0, 1, 0, -1 };

    while (true) {
        cin >> r >> c;

        if (r == 0 && c == 0) {
            break;
        }

        int irq[r][c];
        memset(irq, 0, sizeof(irq));
        cin >> brn;

        for (int i = 0; i < brn; i++) {
            cin >> br >> n;

            for (int j = 0; j < n; j++) {
                cin >> bc;
                irq[br][bc] = 1;
            }
        }

        cin >> sr >> sc;
        cin >> dr >> dc;
        vector<vector<int>> dist(r, vector<int>(c, -1));
        dist[sr][sc] = 0;
        queue<pair<int, int>> q;
        q.push(make_pair(sr, sc));

        while (!q.empty()) {
            pair<int, int> u = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                pair<int, int> v
                    = make_pair(u.first + adjr[i], u.second + adjc[i]);

                if (v.first >= 0 && v.first < r && v.second >= 0 && v.second < c
                    && !irq[v.first][v.second]
                    && dist[v.first][v.second] == -1) {
                    dist[v.first][v.second] = dist[u.first][u.second] + 1;
                    q.push(v);
                }
            }
        }

        cout << dist[dr][dc] << '\n';
    }
}
