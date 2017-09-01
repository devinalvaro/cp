#include <bits/stdc++.h>

using namespace std;

void dfs(int u, map<int, vector<int>> &adjacents, vector<bool> &visited,
         vector<vector<int>> &components)
{
    visited[u] = true;

    int last = components.size() - 1;
    components[last].push_back(u);

    for (int j = 0; j < (int)adjacents[u].size(); j++) {
        int v = adjacents[u][j];

        if (!visited[v]) {
            dfs(v, adjacents, visited, components);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);

    int n, p;
    cin >> n >> p;

    map<int, vector<int>> adjacents;

    while (p--) {
        int u, v;
        cin >> u >> v;

        adjacents[u].push_back(v);
        adjacents[v].push_back(u);
    }

    vector<bool> visited(n);
    vector<vector<int>> components;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            components.push_back({});
            dfs(i, adjacents, visited, components);
        }
    }

    long long pairNumber = 0;
    for (int i = 0; i < (int)components.size(); i++) {
        pairNumber += (components[i].size() * (n - components[i].size()));
    }
    cout << pairNumber / 2 << '\n';
}
