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

map<int, vector<pair<int, long long>>> edges;
stack<int> topo_order;
vector<bool> visited;
vector<long long> dist;

void dfs(int u)
{
    visited[u] = true;

    for (int j = 0; j < (int)edges[u].size(); j++) {
        pair<int, long long> v = edges[u][j];

        if (!visited[v.first]) {
            dfs(v.first);
        }
    }

    topo_order.push(u);
}

int main()
{
    ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b, t;
        cin >> a >> b >> t;

        edges[a - 1].push_back(pair<int, long long>(b - 1, t));
    }

    visited.assign(n, false);
    dfs(0);

    dist.assign(n, LLONG_MIN);
    dist[0] = 0;
    while (!topo_order.empty()) {
        int u = topo_order.top();
        topo_order.pop();

        if (dist[u] == LLONG_MIN) {
            continue;
        }

        for (int j = 0; j < (int)edges[u].size(); j++) {
            pair<int, long long> v = edges[u][j];

            dist[v.first] = max(dist[v.first], dist[u] + v.second);
        }
    }

    cout << (dist[n - 1] == LLONG_MIN ? -1 : dist[n - 1]) << '\n';
}
