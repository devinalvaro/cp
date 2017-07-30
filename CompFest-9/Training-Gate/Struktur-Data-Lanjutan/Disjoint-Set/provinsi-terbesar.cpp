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
vector<long long> size;

int find(int u)
{
    return (parent[u] == u ? u : find(parent[u]));
}

void merge(int ancestor_u, int ancestor_v)
{
    if (level[ancestor_u] > level[ancestor_v]) {
        parent[ancestor_v] = ancestor_u;
    } else {
        parent[ancestor_u] = ancestor_v;

        if (level[ancestor_u] == level[ancestor_v]) {
            level[ancestor_v]++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    parent.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    level.assign(n + 1, 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        int ancestor_u = find(u);
        int ancestor_v = find(v);

        if (ancestor_u == ancestor_v)
            continue;

        merge(ancestor_u, ancestor_v);
    }

    size.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        size[find(i)]++;
    }

    cout << (long long)pow(*max_element(size.begin(), size.end()), 2) << '\n';
}
