#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;

void find_depth(int u, int d, map<int, vector<int>> &adj,
                     vector<int> &depth, vector<bool> &visited,
                     vector<int> &parent, long long &result)
{
    depth[u] = d;
    visited[u] = true;

    for (int j = 0; j < (int)adj[u].size(); j++) {
        int v = adj[u][j];

        if (!visited[v]) {
            /* cout << u << ' ' << v << '\n'; */

            parent[v] = u;

            find_depth(v, d + 1, adj, depth, visited, parent, result);
        } else if (depth[u] > depth[v] && parent[u] != v) {
            /* cout << u << ' ' << v << ": " << depth[u] - depth[v] + 1 << '\n'; */

            result *= (long long)((depth[u] - depth[v]) + 1);
            result %= MOD;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        map<int, vector<int>> adj;
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> depth(n), parent(n);
        vector<bool> visited(n, false);
        long long result = 1;
        find_depth(0, 0, adj, depth, visited, parent, result);

        cout << result << '\n';
    }
}
