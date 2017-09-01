#include <bits/stdc++.h>

using namespace std;

void dfs(int u, map<int, vector<int>> &adjacent, vector<bool> &visited,
         vector<vector<int>> &components)
{
    visited[u] = true;

    int last = components.size() - 1;
    components[last].push_back(u);

    for (int j = 0; j < (int)adjacent[u].size(); j++) {
        int v = adjacent[u][j];

        if (!visited[v]) {
            dfs(v, adjacent, visited, components);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);

    int q;
    cin >> q;

    while (q--) {
        int n, m;
        long long croad, clib;
        cin >> n >> m >> clib >> croad;

        map<int, vector<int>> adjacent;

        while (m--) {
            int u, v;
            cin >> u >> v;
            u--;
            v--;

            adjacent[u].push_back(v);
            adjacent[v].push_back(u);
        }

        if (clib <= croad) {
            cout << clib * n << '\n';

            continue;
        }

        vector<bool> visited(n);
        vector<vector<int>> components;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                components.push_back({});
                dfs(i, adjacent, visited, components);
            }
        }

        long long totalCost = 0;
        for (int i = 0; i < (int)components.size(); i++) {
            totalCost += (clib + ((components[i].size() - 1) * croad));
        }
        cout << totalCost << '\n';
    }
}
