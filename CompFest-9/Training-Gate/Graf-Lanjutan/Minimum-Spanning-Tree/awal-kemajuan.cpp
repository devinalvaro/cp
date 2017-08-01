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

class UFDS {
private:
    vector<int> parent;
    vector<int> level;

public:
    int find(int u) { return (parent[u] == u ? u : find(parent[u])); }

    void merge(int u, int v) {
        int ancestor_u = find(u);
        int ancestor_v = find(v);

        if (ancestor_u == ancestor_v) {
            return;
        }

        if (level[ancestor_u] > level[ancestor_v]) {
            parent[ancestor_v] = ancestor_u;
        } else {
            parent[ancestor_u] = ancestor_v;

            if (level[ancestor_u] == level[ancestor_v]) {
                level[ancestor_v]++;
            }
        }
    }

    UFDS(int n) {
        parent.assign(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }

        level.assign(n + 1, 1);
    }
};

int main() {
    ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    vector<pair<long long, pair<int, int>>> edges_list;
    while (m--) {
        int u, v;
        long long w;
        cin >> u >> v >> w;

        edges_list.push_back(make_pair(w, make_pair(u, v)));
    }

    sort(edges_list.begin(), edges_list.end());

    UFDS ufds(n);
    long long mst_cost = 0;

    for (size_t i = 0; i < edges_list.size(); i++) {
        int u = edges_list[i].second.first;
        int v = edges_list[i].second.second;
        long long w = edges_list[i].first;

        if (ufds.find(u) != ufds.find(v)) {
            ufds.merge(u, v);

            mst_cost += w;
        }
    }

    cout << mst_cost << '\n';
}
