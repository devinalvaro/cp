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
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    UFDS ufds(2 * n);

    for (int i = 0; i < n; i++) {
        int g, b;
        cin >> g >> b;

        ufds.merge(g, b);
    }

    int mini = INT_MAX, maxi = INT_MIN;

    for (int i = 1; i <= 2 * n; i++) {
        int set_size = ufds.get_set_size(i);

        if (set_size <= 1)
            continue;

        mini = min(mini, set_size);
        maxi = max(maxi, set_size);
    }

    cout << mini << ' ' << maxi << '\n';
}
