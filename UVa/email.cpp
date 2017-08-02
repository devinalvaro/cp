/* graph : sssp (dijkstra) */

#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);

    int tc, tcn = 0;
    cin >> tc;

    map<int, vector<pair<int, int>>> adj;
    vector<int> dist;
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;

    while (tc--) {
        int n, m, s, t;
        cin >> n >> m >> s >> t;

        adj.clear();

        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;

            adj[u].push_back(pair<int, int>(w, v));
            adj[v].push_back(pair<int, int>(w, u));
        }

        dist.clear();
        dist.assign(n, INT_MAX);
        dist[s] = 0;

        pq.push(pair<int, int>(0, s));

        while (!pq.empty()) {
            pair<int, int> choice = pq.top();
            pq.pop();

            int d = choice.first;
            int u = choice.second;

            if (d <= dist[u]) {
                for (int j = 0; j < (int)adj[u].size(); j++) {
                    pair<int, int> v = adj[u][j];

                    if (dist[u] + v.first < dist[v.second]) {
                        dist[v.second] = dist[u] + v.first;
                        pq.push(pair<int, int>(dist[v.second], v.second));
                    }
                }
            }
        }

        cout << "Case #" << ++tcn << ": ";

        if (dist[t] == INT_MAX) {
            cout << "unreachable" << '\n';
        } else {
            cout << dist[t] << '\n';
        }
    }
}
