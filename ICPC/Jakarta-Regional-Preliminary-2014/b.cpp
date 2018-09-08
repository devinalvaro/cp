#include <bits/stdc++.h>

using namespace std;

int main() {
    int tc;
    cin >> tc;

    for (int tn = 1; tn <= tc; tn++) {
        cout << "Case #" << tn << ":\n";

        int n, m;
        cin >> n >> m;

        map<int, vector<pair<int, int>>> adj;
        while (m--) {
            int u, v;
            cin >> u >> v;

            adj[u].push_back(make_pair(0, v));
            adj[v].push_back(make_pair(1, u));
        }

        int q;
        cin >> q;

        while (q--) {
            int u, v;
            cin >> u >> v;

            vector<int> dist(n + 1, INT_MAX);
            dist[u] = 0;

            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            pq.push(make_pair(dist[u], u));

            while (!pq.empty()) {
                int u = pq.top().second;
                int d = pq.top().first;
                pq.pop();

                if (d > dist[u])
                    continue;

                for (int j = 0; j < (int)adj[u].size(); j++) {
                    int v = adj[u][j].second;
                    int d = adj[u][j].first;

                    if (dist[u] + d < dist[v]) {
                        dist[v] = dist[u] + d;

                        pq.push(make_pair(dist[v], v));
                    }
                }
            }

            cout << (dist[v] == INT_MAX ? -1 : dist[v]) << '\n';
        }
    }
}
