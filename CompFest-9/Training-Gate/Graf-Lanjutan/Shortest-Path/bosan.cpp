#include <algorithm>
#include <bitset>
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

const int MOD = 1000000007;

/**
 * n: number of nodes in graph
 * s: starting node
 * edges: edges[u][j] = v means u is adjacent or neighbor with v
 * dist: resulting vector where distance[e] is distance of e from s
 */
void dijkstra(int n, int s, map<int, vector<pair<int, int>>> &edges,
              vector<int> &dist) {
    dist.assign(n + 1, INT_MAX);
    dist[s] = 0; // start at node s

    // priority queue of <dist[node], node> with nearest node on top
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    pq.push(pair<int, int>(dist[s], s));

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u])
            continue; // lazy deletion

        for (size_t j = 0; j < edges[u].size(); j++) {
            int v = edges[u][j].second;
            int h = edges[u][j].first;

            if (dist[u] + h < dist[v]) {
                dist[v] = dist[u] + h;

                pq.push(pair<int, int>(dist[v], v));
            }
        }
    }
}

int count_ways(int u, vector<int> &ways,
               map<int, vector<pair<int, int>>> &edges,
               const vector<int> &dist) {
    if (ways[u] != -1)
        return ways[u] % MOD;

    ways[u] = 0;
    for (size_t j = 0; j < edges[u].size(); j++) {
        int v = edges[u][j].second;
        int w = edges[u][j].first;

        if (dist[u] == dist[v] + w) {
            ways[u] += (count_ways(v, ways, edges, dist) % MOD);
            ways[u] %= MOD;
        }
    }

    return ways[u] % MOD;
}

int main() {
    ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    map<int, vector<pair<int, int>>> edges;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        edges[u].push_back(make_pair(w, v));
        edges[v].push_back(make_pair(w, u));
    }

    vector<int> dist;
    dijkstra(n, 1, edges, dist);

    vector<int> ways(n + 1, -1);
    ways[1] = 1;

    cout << count_ways(n, ways, edges, dist) % MOD << '\n';
}
