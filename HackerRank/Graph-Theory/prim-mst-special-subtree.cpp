#include <bits/stdc++.h>

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

int kruskal(int n, vector<pair<int, pair<int, int>>> &edges_list)
{
    sort(edges_list.begin(), edges_list.end());

    UFDS ufds(n);
    int mst_cost = 0;

    for (size_t i = 0; i < edges_list.size(); i++) {
        int u = edges_list[i].second.first;
        int v = edges_list[i].second.second;
        int w = edges_list[i].first;

        if (ufds.find(u) != ufds.find(v)) {
            ufds.merge(u, v);

            mst_cost += w;
        }
    }

    return mst_cost;
}

int main()
{
    ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    vector<pair<int, pair<int, int>>> edges_list;

    while (m--) {
        int x, y, r;
        cin >> x >> y >> r;

        edges_list.push_back(make_pair(r, make_pair(x, y)));
    }

    cout << kruskal(n, edges_list) << '\n';
}
