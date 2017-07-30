#include <climits>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<int, iii> iiii;

int dir[][4]
    = { { 1, 0, 0, 0 }, { -1, 0, 0, 0 }, { 0, 1, 0, 0 }, { 0, -1, 0, 0 },
        { 0, 0, 1, 0 }, { 0, 0, -1, 0 }, { 0, 0, 0, 1 }, { 0, 0, 0, -1 } };

int main()
{
    int t, n;
    int s1, s2, s3, s4;
    int t1, t2, t3, t4;
    int f1, f2, f3, f4;
    int conf[10][10][10][10];
    int dist[10][10][10][10];

    cin >> t;
    while (t--) {
        memset(conf, 0, sizeof(conf));
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++)
                for (int k = 0; k < 10; k++)
                    for (int l = 0; l < 10; l++)
                        dist[i][j][k][l] = INT_MAX;

        cin >> s1 >> s2 >> s3 >> s4;
        cin >> t1 >> t2 >> t3 >> t4;

        cin >> n;
        while (n--) {
            cin >> f1 >> f2 >> f3 >> f4;
            conf[f1][f2][f3][f4] = -1;
        }

        dist[s1][s2][s3][s4] = 0;
        queue<iiii> q;
        q.push(iiii(s1, iii(s2, ii(s3, s4))));
        while (!q.empty()) {
            iiii u = q.front();
            q.pop();

            int u1 = u.first == -1 ? 9 : u.first % 10;
            int u2 = u.second.first == -1 ? 9 : u.second.first % 10;
            int u3
                = u.second.second.first == -1 ? 9 : u.second.second.first % 10;
            int u4 = u.second.second.second == -1 ? 9
                                                  : u.second.second.second % 10;

            for (int i = 0; i < 8; i++) {
                iiii v(u1 + dir[i][0],
                    iii(u2 + dir[i][1], ii(u3 + dir[i][2], u4 + dir[i][3])));

                int v1 = v.first == -1 ? 9 : v.first % 10;
                int v2 = v.second.first == -1 ? 9 : v.second.first % 10;
                int v3 = v.second.second.first == -1
                    ? 9
                    : v.second.second.first % 10;
                int v4 = v.second.second.second == -1
                    ? 9
                    : v.second.second.second % 10;

                if (conf[v1][v2][v3][v4] == -1)
                    continue;

                if (dist[v1][v2][v3][v4] == INT_MAX) {
                    dist[v1][v2][v3][v4] = dist[u1][u2][u3][u4] + 1;
                    q.push(v);
                }
            }
        }

        if (dist[t1][t2][t3][t4] == INT_MAX)
            cout << -1 << endl;
        else
            cout << dist[t1][t2][t3][t4] << endl;
    }
}
