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

class UFDS
{
private:
    vector<int> parent;
    vector<int> level;

public:
    int find(int u) { return (parent[u] == u ? u : find(parent[u])); }

    void merge(int u, int v)
    {
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

    UFDS(int n)
    {
        parent.assign(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }

        level.assign(n + 1, 1);
    }
};

int main()
{
    ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    vector<pair<int, pair<int, int>>> edges_list;
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;

        edges_list.push_back(make_pair(c, make_pair(a, b)));
    }

    sort(edges_list.begin(), edges_list.end());

    UFDS ufds(n);
    int mst_cost = 0;

    for (size_t i = 0; i < edges_list.size(); i++) {
        int a = edges_list[i].second.first;
        int b = edges_list[i].second.second;
        int c = edges_list[i].first;

        if (ufds.find(a) != ufds.find(b)) {
            ufds.merge(a, b);

            mst_cost += c;
        }
    }

    cout << mst_cost << '\n';
}
