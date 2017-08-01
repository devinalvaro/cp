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

bool topo_sort(const vector<vector<int>> &edge, vector<int> &visited, int u,
               vector<int> &topo_array) {
    visited[u] = 1;
    bool check = true;

    for (size_t j = 0; j < edge[u].size(); j++) {
        int v = edge[u][j];

        if (visited[v] == 1)
            return false;

        if (visited[v] == 0) {
            check = check && topo_sort(edge, visited, v, topo_array);
        }
    }

    topo_array.push_back(u);

    visited[u] = 2;
    return check;
}

int main() {
    ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> edge(n + 1, vector<int>());
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;

        edge[x].push_back(y);
    }

    vector<int> visited(n + 1, false);
    vector<int> topo_array;
    bool cyclic = false;
    for (int i = 1; i <= n; i++) {
        if (visited[i] == 0) {
            if (!topo_sort(edge, visited, i, topo_array)) {
                cyclic = true;

                break;
            }
        }
    }

    if (cyclic) {
        for (int i = 1; i <= n; i++) {
            cout << -1 << (i == n ? '\n' : ' ');
        }
    } else {
        for (int i = topo_array.size() - 1; i >= 0; i--) {
            cout << (cyclic ? -1 : topo_array[i]) << (i == 0 ? '\n' : ' ');
        }
    }
}
