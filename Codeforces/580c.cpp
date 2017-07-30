#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

int n, m, r = 0;

map<int, vector<int>> adj;
vector<int> cats;
vector<bool> visited;

void dfs(int u, int c)
{
    if (c > m) {
        return;
    }

    visited[u] = true;
    bool leaf = true;

    for (int j = 0; j < (int)adj[u].size(); j++) {
        int v = adj[u][j];

        if (!visited[v]) {
            leaf = false;

            dfs(v, (cats[v] == 1 ? c + cats[v] : 0));
        }
    }

    if (leaf) {
        r++;
    }
}

int main()
{
    cin >> n >> m;

    visited.assign(n, false);
    cats.assign(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> cats[i];
    }

    int u, v;
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }

    dfs(0, cats[0]);

    cout << r << endl;
}