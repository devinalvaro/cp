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
    int n, m, k;
    cin >> n >> m >> k;

    map<int, vector<int>> edges;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        edges[u - 1].push_back(v - 1);
        edges[v - 1].push_back(u - 1);
    }

    vector<int> f(n);
    f[0] = 0;
    for (int i = 1; i <= k; i++) {
        cin >> f[i];
        f[i]--;
    }

    vector<vector<int>> dist(k + 1, vector<int>(n, INT_MAX));

    for (int i = 0; i <= k; i++) {
        dist[i][f[i]] = 0;

        queue<int> q;
        q.push(f[i]);
        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int j = 0; j < (int)edges[u].size(); j++) {
                int v = edges[u][j];

                if (dist[i][v] == INT_MAX) {
                    dist[i][v] = dist[i][u] + 1;

                    q.push(v);
                }
            }
        }
    }

    vector<vector<int>> neighbor_dist(k + 1, vector<int>(k + 1));
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j <= k; j++) {
            neighbor_dist[i][j] = dist[i][f[j]];
        }
    }

    vector<int> order(k + 1);
    for (int i = 0; i <= k; i++) {
        order[i] = i;
    }

    int best_dist = INT_MAX;
    while (next_permutation(order.begin(), order.end())) {
        int path_dist = 0;

        for (int i = 0; i < k; i++) {
            path_dist += neighbor_dist[order[i]][order[i + 1]];
        }
        path_dist += neighbor_dist[order[k]][order[0]];

        best_dist = min(best_dist, path_dist);
    }

    cout << best_dist << '\n';
}
