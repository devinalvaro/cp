/* graph : articulation and bridges */

#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int traverse, root, rootChildren, discovery[10001], low[10001], parent[10001],
    pigeon[10001];
bool visited[10001], articulation[10001];
map<int, vector<int>> adj;
vector<pair<int, int>> candidates;

bool compare(pair<int, int> a, pair<int, int> b)
{
    if (a.second == b.second) {
        return a.first < b.first;
    } else {
        return a.second > b.second;
    }
}

void articulationDFS(int u)
{
    visited[u] = true;
    discovery[u] = low[u] = ++traverse;

    for (int j = 0; j < (int)adj[u].size(); j++) {
        int v = adj[u][j];

        if (!visited[v]) { // u becomes parent of v
            parent[v] = u;
            articulationDFS(v);

            if (low[v] >= discovery[u]) {
                if (u == root && rootChildren <= 1) {
                    rootChildren++;
                    pigeon[u] = rootChildren - 1;
                } else {
                    pigeon[u]++;
                    articulation[u] = true;
                }
            }

            low[u] = min(low[u], low[v]);
        } else if (v != parent[u]) {
            low[u] = min(low[u], discovery[v]);
        }
    }
}

int main()
{
    int n, m, u, v;

    while (cin >> n >> m) {
        if (n == 0 && m == 0) {
            break;
        }

        memset(discovery, 0, sizeof(discovery));
        memset(low, 0, sizeof(low));
        memset(parent, 0, sizeof(parent));
        memset(pigeon, 0, sizeof(pigeon));
        memset(visited, false, sizeof(visited));
        memset(articulation, false, sizeof(articulation));
        adj.clear();
        candidates.clear();

        while (cin >> u >> v) {
            if (u == -1 && v == -1) {
                break;
            }

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        traverse = 0;
        int island = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                root = i;
                rootChildren = 0;
                island++;
                articulationDFS(i);
            }
        }

        for (int i = 0; i < n; i++) {
            candidates.push_back(make_pair(i, pigeon[i] + island));
        }

        sort(candidates.begin(), candidates.end(),
            [](const pair<int, int>& a, const pair<int, int>& b) {
                return compare(a, b);
            });

        for (int i = 0; i < m; i++) {
            cout << candidates[i].first << ' ' << candidates[i].second << '\n';
        }

        cout << '\n';
    }
}
