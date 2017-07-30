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

vector<int> parent, level;

int find(int u)
{
    return (parent[u] == u ? u : find(parent[u]));
}

bool merge(int u, int v)
{
    int ancestor_u = find(u);
    int ancestor_v = find(v);

    if (ancestor_u == ancestor_v) {
        return true;
    }

    if (level[ancestor_u] > level[ancestor_v]) {
        parent[ancestor_v] = ancestor_u;
    } else {
        parent[ancestor_u] = ancestor_v;

        if (level[ancestor_u] == level[ancestor_v]) {
            level[ancestor_v]++;
        }
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    parent.assign(n + 1, -1);
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    level.assign(n + 1, 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        if (merge(u, v)) {
            cout << i + 1 << '\n';

            return 0;
        }
    }

    cout << -1 << '\n';
}
