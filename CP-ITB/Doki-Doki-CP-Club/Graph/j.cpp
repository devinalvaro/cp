/* Blackout */

#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

vector<int> parent, ranks;
vector<pair<int, pair<int, int>>> edges;

int findSet(int u) {
    return parent[u] == u ? u : findSet(parent[u]);
}

bool isSameSet(int u, int v) {
    return findSet(u) == findSet(v);
}

void join(int u, int v) {
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

void createUFDS(int n) {
    edges.clear();
    ranks.assign(n + 1, 0);
    parent.assign(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    int t, n, m, u, v, w;
    cin >> t;

    while (t--) {
        cin >> n >> m;
        createUFDS(n);

        for (int i = 0; i < m; i++) {
            cin >> u >> v >> w;
            edges.push_back(make_pair(w, make_pair(u, v)));
        }

        sort(edges.begin(), edges.end());
        int mstCost = 0;
        vector<int> mstEdges;

        for (int i = 0; i < m; i++) {
            pair<int, pair<int, int>> e = edges[i];

            if (!isSameSet(e.second.first, e.second.second)) {
                mstCost += e.first;
                mstEdges.push_back(i);
                join(e.second.first, e.second.second);
            }
        }

        cout << mstCost << ' ';
        int secondMSTCost = INT_MAX;

        for (int i = 0; i < (int)mstEdges.size(); i++) {
            createUFDS(n);
            mstCost = 0;
            vector<int> secondMSTEdges;

            for (int j = 0; j < m; j++) {
                if (j == mstEdges[i]) {
                    continue;
                }

                pair<int, pair<int, int>> e = edges[j];

                if (!isSameSet(e.second.first, e.second.second)) {
                    mstCost += e.first;
                    secondMSTEdges.push_back(j);
                    join(e.second.first, e.second.second);
                }
            }

            if (secondMSTEdges.size() == mstEdges.size()) {
                secondMSTCost = min(secondMSTCost, mstCost);
            }
        }

        cout << secondMSTCost << '\n';
    }
}
