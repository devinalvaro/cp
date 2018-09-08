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

int main()
{
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    vector<vector<int>> edges(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;

        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    vector<int> dist(n + 1, -1);
    dist[1] = 0;
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int i = 0; i < (int)edges[u].size(); i++) {
            int v = edges[u][i];

            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;

                q.push(v);
            }
        }
    }

    int start = max_element(dist.begin() + 1, dist.end()) - dist.begin();

    dist.assign(n + 1, -1);
    dist[start] = 0;
    q.push(start);
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int i = 0; i < (int)edges[u].size(); i++) {
            int v = edges[u][i];

            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;

                q.push(v);
            }
        }
    }

    cout << *max_element(dist.begin() + 1, dist.end()) << '\n';
}
