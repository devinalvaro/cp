#include <bits/stdc++.h>

using namespace std;

class UFDS
{
private:
    vector<int> parent;
    vector<int> level;
    vector<int> set_size;

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

            set_size[ancestor_u] += set_size[ancestor_v];
            set_size[ancestor_v] = 0;
        } else {
            parent[ancestor_u] = ancestor_v;

            set_size[ancestor_v] += set_size[ancestor_u];
            set_size[ancestor_u] = 0;

            if (level[ancestor_u] == level[ancestor_v]) {
                level[ancestor_v]++;
            }
        }
    }

    int get_set_size(int u) { return set_size[find(u)]; }

    UFDS(int n)
    {
        parent.assign(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }

        level.assign(n + 1, 1);

        set_size.assign(n + 1, 1);
    }
};

int main()
{
    int n, q;
    cin >> n >> q;

    UFDS ufds(n);

    while (q--) {
        char c;
        cin >> c;

        if (c == 'Q') {
            int u;
            cin >> u;

            cout << ufds.get_set_size(u) << '\n';
        } else if (c == 'M') {
            int u, v;
            cin >> u >> v;

            ufds.merge(u, v);
        }
    }
}
