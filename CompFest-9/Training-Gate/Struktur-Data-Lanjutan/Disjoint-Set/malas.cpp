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

vector<int> parent, level, size;

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

        size[ancestor_u] += size[ancestor_v];
        size[ancestor_v] = 0;
    } else {
        parent[ancestor_u] = ancestor_v;

        size[ancestor_v] += size[ancestor_u];
        size[ancestor_u] = 0;

        if (level[ancestor_u] == level[ancestor_v]) {
            level[ancestor_v]++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);

    int n, q;
    cin >> n >> q;

    parent.assign(n + 1, -1);
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    level.assign(n + 1, 1);

    size.assign(n + 1, 1);
    while (q--) {
        int k, a, b;
        cin >> k >> a >> b;

        if (k == 1) {
            merge(a, b);
        } else if (k == 2) {
            cout << size[find(a)] << '\n';
        }
    }
}
