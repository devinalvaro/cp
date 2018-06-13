#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ll long long
#define ve vector
#define um unordered_map
#define us unordered_set

bool found, visited[300001];
int x, y, z;
ll size[300001];
um<int, ve<int>> edges;

void dfs(int u) {
    visited[u] = true;

    if (u == x) {
        found = true;
    }

    for (int v : edges[u]) {
        if (u == y && !found) {
            z = v;
        }

        if (!visited[v]) {
            dfs(v);
            size[u] += size[v];
        }
    }
}

int main() {
    ll n;
    cin >> n >> x >> y;

    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;

        edges[u].pb(v);
        edges[v].pb(u);

        size[i + 1] = 1;
    }

    dfs(y);

    cout << (n * (n - 1)) - (size[x] * (size[y] - size[z])) << endl;

    return 0;
}
