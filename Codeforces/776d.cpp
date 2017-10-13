#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> doors(n);
    for (int i = 0; i < n; i++) {
        cin >> doors[i];
    }

    vector<vector<int>> edges(n);
    for (int i = 0; i < m; i++) {
        int size;
        cin >> size;

        for (int j = 0; j < size; j++) {
            int u;
            cin >> u;

            edges[u - 1].push_back(i);
        }
    }

    map<int, vector<pair<int, int>>> adj;
    for (int i = 0; i < n; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(make_pair(v, doors[i]));
        adj[v].push_back(make_pair(u, doors[i]));
    }

    vector<int> colors(m, -1);
    for (int i = 0; i < m; i++) {
        if (colors[i] != -1)
            continue;

        colors[i] = 0;

        queue<int> q;
        q.push(i);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int j = 0; j < (int)adj[u].size(); j++) {
                int v = adj[u][j].first;
                int door = adj[u][j].second;

                int color = (door ? colors[u] : 1 - colors[u]);

                if (colors[v] == -1) {
                    colors[v] = color;

                    q.push(v);
                } else if (colors[v] != color) {
                    cout << "NO\n";

                    return 0;
                }
            }
        }
    }

    cout << "YES\n";
}
