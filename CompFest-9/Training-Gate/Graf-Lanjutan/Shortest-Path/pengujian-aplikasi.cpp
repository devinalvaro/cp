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

void find_path(int a, int b, const vector<vector<int>> &parent,
               vector<int> &shortest_path) {
    if (a != b) {
        find_path(a, parent[a][b], parent, shortest_path);
    }

    shortest_path.push_back(b);
}

int main() {
    ios_base::sync_with_stdio(0);

    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> adjacent(n + 1, vector<int>(n + 1, 1e9));
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;

        adjacent[u][v] = w;
        adjacent[v][u] = w;
    }

    vector<vector<int>> parent(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            parent[i][j] = i;
        }
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (adjacent[i][j] > adjacent[i][k] + adjacent[k][j]) {
                    adjacent[i][j] = adjacent[i][k] + adjacent[k][j];
                    parent[i][j] = parent[k][j];
                }
            }
        }
    }

    while (q--) {
        int a, b;
        cin >> a >> b;

        vector<int> shortest_path;
        find_path(a, b, parent, shortest_path);

        for (size_t i = 0; i < shortest_path.size(); i++) {
            cout << shortest_path[i]
                 << (i == shortest_path.size() - 1 ? '\n' : ' ');
        }
    }
}
