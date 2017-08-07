/* graph : mst */

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int n, m;
vector<int> parent, ranks;
vector<pair<int, pair<int, int>>> edges;

int findSet(int i) { return parent[i] == i ? i : findSet(parent[i]); }
bool isSameSet(int u, int v) { return findSet(u) == findSet(v); }

void joinSet(int u, int v)
{
    if (!isSameSet(u, v)) {
        int x = findSet(u), y = findSet(v);

        if (ranks[x] > ranks[y]) {
            parent[y] = x;
        } else {
            parent[x] = y;

            if (ranks[x] == ranks[y]) {
                ranks[y]++;
            }
        }
    }
}

int main()
{
    int u, v, w;

    while (cin >> n >> m) {
        if (n == 0 && m == 0) {
            break;
        }

        parent.assign(n, 0);
        ranks.assign(n, 0);
        edges.clear();

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        int totalCost = 0;

        for (int i = 0; i < m; i++) {
            cin >> u >> v >> w;
            totalCost += w;
            edges.push_back(make_pair(w, make_pair(u, v)));
            edges.push_back(make_pair(w, make_pair(v, u)));
        }

        sort(edges.begin(), edges.end());
        int mstCost = 0;

        for (int i = 0; i < 2 * m; i++) {
            pair<int, pair<int, int>> currentEdge = edges[i];

            if (!isSameSet(currentEdge.second.first,
                           currentEdge.second.second)) {
                mstCost += currentEdge.first;
                joinSet(currentEdge.second.first, currentEdge.second.second);
            }
        }

        cout << totalCost - mstCost << '\n';
    }
}
