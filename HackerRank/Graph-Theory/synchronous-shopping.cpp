#include <bits/stdc++.h>

using namespace std;

void dijkstra(int n, int k, int s, vector<int> &fish,
              map<int, vector<pair<int, int>>> &edges,
              vector<vector<int>> &dist)
{
    dist.assign(n, vector<int>(1 << k, INT_MAX));
    dist[s][fish[0]] = 0;

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                   greater<pair<int, pair<int, int>>>>
        pq;
    pq.push(make_pair(dist[s][fish[0]], make_pair(s, fish[0])));

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second.first;
        int fish_u = pq.top().second.second;
        pq.pop();

        if (d > dist[u][fish_u])
            continue; // lazy deletion

        for (int j = 0; j < (int)edges[u].size(); j++) {
            int d = edges[u][j].first;
            int v = edges[u][j].second;
            int fish_v = fish[v] | fish_u;

            if (dist[u][fish_u] + d < dist[v][fish_v]) {
                dist[v][fish_v] = dist[u][fish_u] + d;

                pq.push(make_pair(dist[v][fish_v], make_pair(v, fish_v)));
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> fish(n, 0);

    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;

        for (int j = 0; j < t; j++) {
            int k;
            cin >> k;

            fish[i] |= (1 << (k - 1));
        }
    }

    map<int, vector<pair<int, int>>> edges;

    for (int i = 0; i < m; i++) {
        int u, v, d;
        cin >> u >> v >> d;

        edges[u - 1].push_back(make_pair(d, v - 1));
        edges[v - 1].push_back(make_pair(d, u - 1));
    }

    vector<vector<int>> dist;

    dijkstra(n, k, 0, fish, edges, dist);

    int min_dist = INT_MAX;
    for (int i = 0; i < (1 << k); i++) {
        for (int j = 0; j < (1 << k); j++) {
            if ((i | j) == (1 << k) - 1) {
                min_dist = min(min_dist, max(dist[n - 1][i], dist[n - 1][j]));
            }
        }
    }
    cout << min_dist << '\n';
}
