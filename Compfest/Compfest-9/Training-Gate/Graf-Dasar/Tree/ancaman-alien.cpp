#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

int n;
vector<vector<int>> edges, children, ancestors;
vector<bool> visited;
vector<int> height, depth, parent;

void generate_tree(int u)
{
    visited[u] = true;

    for (int j = 0; j < (int)edges[u].size(); j++) {
        int v = edges[u][j];
        if (!visited[v]) {
            children[u].push_back(v);
            parent[v] = u;

            generate_tree(v);
        }
    }
}

void find_depths(int u, int d)
{
    depth[u] = d;

    for (int j = 0; j < (int)children[u].size(); j++) {
        int v = children[u][j];
        find_depths(v, d + 1);
    }
}

int find_ancestor(int u, int k)
{
    int ancestor = u;
    int bitlen = (int)log2(k) + 1;
    for (int i = 0; i < bitlen; i++) {
        if (k & (1 << i)) {
            ancestor = ancestors[ancestor][i];
        }
    }
    return ancestor;
}

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> n;

    int u, v;
    edges.assign(n + 1, vector<int>());
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;

        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    children.assign(n + 1, vector<int>());
    parent.assign(n + 1, -1);
    visited.assign(n + 1, false);
    generate_tree(1);

    depth.assign(n + 1, 0);
    find_depths(1, 0);
    int max_depth = *max_element(depth.begin(), depth.end());
    int lg_max_depth = (max_depth == 0 ? 0 : (int)log2(max_depth)) + 1;

    ancestors.assign(n + 1, vector<int>(lg_max_depth, -1));
    for (int i = 1; i <= n; i++) {
        ancestors[i][0] = parent[i];
    }
    for (int j = 1; j < lg_max_depth; j++) {
        for (int i = 1; i <= n; i++) {
            if (ancestors[i][j - 1] != -1) {
                ancestors[i][j] = ancestors[ancestors[i][j - 1]][j - 1];
            }
        }
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;

        int k = depth[v] - depth[u];

        if (u == v || (k > 0 && find_ancestor(v, k) == u)) {
            cout << "TIDAK\n";
        } else {
            cout << "YA\n";
        }
    }
}
