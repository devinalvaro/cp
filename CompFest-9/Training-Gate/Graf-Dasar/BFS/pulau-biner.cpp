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
using ii = pair<int, int>;
using iii = pair<int, pair<int, int>>;

int main()
{
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    vector<vector<char>> pulau(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> pulau[i][j];
        }
    }

    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
    dist[0][0] = 0;

    priority_queue<iii, vector<iii>, greater<iii>> pq;
    pq.push(iii(dist[0][0], ii(0, 0)));
    while (!pq.empty()) {
        int d = pq.top().first;
        ii u = pq.top().second;
        pq.pop();

        if (d > dist[u.first][u.second])
            continue;

        vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int i = 0; i < 4; i++) {
            ii v(u.first + dir[i][0], u.second + dir[i][1]);

            if (v.first < 0 || v.first >= n || v.second < 0 || v.second >= n)
                continue;

            if (dist[u.first][u.second] + (pulau[v.first][v.second] - '0') <
                dist[v.first][v.second]) {
                dist[v.first][v.second] =
                    dist[u.first][u.second] + (pulau[v.first][v.second] - '0');

                pq.push(iii(dist[v.first][v.second], ii(v.first, v.second)));
            }
        }
    }

    cout << dist[n - 1][n - 1] << '\n';
}
