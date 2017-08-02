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

int main()
{
    ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    map<int, vector<pair<long long, int>>> edges;
    for (int i = 0; i < m; i++) {
        int u, v;
        long long h;
        cin >> u >> v >> h;

        edges[u].push_back(pair<long long, int>(h, v));
        edges[v].push_back(pair<long long, int>(h, u));
    }

    vector<long long> dist(n + 1, LLONG_MAX);
    dist[1] = 0;

    priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                   greater<pair<long long, int>>>
        pq;
    pq.push(pair<long long, int>(dist[1], 1));

    while (!pq.empty()) {
        int u = pq.top().second;
        long long d = pq.top().first;
        pq.pop();

        if (d > dist[u])
            continue;

        for (size_t j = 0; j < edges[u].size(); j++) {
            int v = edges[u][j].second;
            long long h = edges[u][j].first;

            if (dist[u] + h < dist[v]) {
                dist[v] = dist[u] + h;

                pq.push(pair<long long, int>(dist[v], v));
            }
        }
    }

    cout << dist[n] << '\n';
}
