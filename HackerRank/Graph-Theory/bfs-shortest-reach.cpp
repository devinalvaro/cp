#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);

    int q;
    cin >> q;

    while (q--) {
        int n, m;
        cin >> n >> m;

        map<int, vector<int>> adjacents;

        while (m--) {
            int u, v;
            cin >> u >> v;
            u--;
            v--;

            adjacents[u].push_back(v);
            adjacents[v].push_back(u);
        }

        int s;
        cin >> s;
        s--;

        vector<int> dist(n, INT_MAX);
        dist[s] = 0;

        queue<int> nodes;
        nodes.push(s);

        while (!nodes.empty()) {
            int u = nodes.front();
            nodes.pop();

            for (int j = 0; j < (int)adjacents[u].size(); j++) {
                int v = adjacents[u][j];

                if (dist[v] == INT_MAX) {
                    dist[v] = dist[u] + 1;

                    nodes.push(v);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (i == s)
                continue;

            if (dist[i] == INT_MAX)
                cout << -1 << (i == n - 1 ? '\n' : ' ');
            else
                cout << dist[i] * 6 << (i == n - 1 ? '\n' : ' ');
        }

        if (s == n - 1) {
            cout << '\n';
        }
    }
}
