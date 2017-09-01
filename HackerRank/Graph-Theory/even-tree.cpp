#include <bits/stdc++.h>

using namespace std;

int dfs(int u, map<int, vector<int>> &adj, vector<bool> &vis, int &ans)
{
    vis[u] = true;

    int treeNodeNumber = 1; // tree with u as root

    for (int j = 0; j < (int)adj[u].size(); j++) {
        int v = adj[u][j];

        if (!vis[v]) {
            int subtreeNodeNumber =
                dfs(v, adj, vis, ans); // subtree with v as root

            if (subtreeNodeNumber % 2 == 0) {
                ans += 1;
            } else {
                treeNodeNumber += subtreeNodeNumber;
            }
        }
    }
    return treeNodeNumber;
}

int main()
{
    ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    map<int, vector<int>> adj;

    while (m--) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = 0;
    vector<bool> vis(n, false);

    dfs(1, adj, vis, ans);
    cout << ans << '\n';
}
