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

bool topo_check(const vector<vector<int>> &edge, vector<int> &visited, int u) {
    visited[u] = 1;
    bool check = true;

    for (size_t j = 0; j < edge[u].size(); j++) {
        int v = edge[u][j];

        if (visited[v] == 1)
            return false;

        if (visited[v] == 0) {
            check = check && topo_check(edge, visited, v);
        }
    }

    visited[u] = 2;
    return check;
}

int main() {
    ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> edge(n + 1, vector<int>());
    vector<int> in_degrees(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;

        edge[x].push_back(y);
        in_degrees[y]++;
    }

    vector<int> visited(n + 1, false);
    for (int i = 1; i <= n; i++) {
        if (visited[i] == 0) {
            if (!topo_check(edge, visited, i)) {
                for (int i = 1; i <= n; i++) {
                    cout << -1 << (i == n ? '\n' : ' ');
                }

                return 0;
            }
        }
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= n; i++) {
        if (in_degrees[i] == 0) {
            pq.push(i);
        }
    }

    vector<int> topo_array;
    while (!pq.empty()) {
        int u = pq.top();
        pq.pop();

        topo_array.push_back(u);

        for (size_t j = 0; j < edge[u].size(); j++) {
            int v = edge[u][j];

            in_degrees[v]--;
            if (in_degrees[v] == 0) {
                pq.push(v);
            }
        }
    }
}
