/* graph : scc */

#include <cstring>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int n, m;
bool visited[2002];
map<int, vector<int>> adj, revAdj;

void dfs(int v)
{
    visited[v] = true;

    for (int i = 0; i < (int)adj[v].size(); i++) {
        int w = adj[v][i];

        if (!visited[w]) {
            dfs(w);
        }
    }
}

bool scc()
{
    memset(visited, false, sizeof(visited));
    dfs(1);

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            return false;
        }
    }

    adj = revAdj;
    memset(visited, false, sizeof(visited));
    dfs(1);

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            return false;
        }
    }

    return true;
}

int main()
{
    int v, w, p;

    while (cin >> n >> m) {
        if (n == 0 && m == 0) {
            break;
        }

        adj.clear();
        revAdj.clear();

        for (int i = 0; i < m; i++) {
            cin >> v >> w >> p;
            adj[v].push_back(w);
            revAdj[w].push_back(v);

            if (p == 2) {
                adj[w].push_back(v);
                revAdj[v].push_back(w);
            }
        }

        cout << scc() << '\n';
    }
}
