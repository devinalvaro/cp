#include <bits/stdc++.h>

using namespace std;

vector<int> dfs_num, dfs_low, s, visitedNode;
vector<vector<int>> adjList;
int dfsCounter, numSCC;

void tarjan(int u, int &jumlah) {
    dfs_num[u] = dfs_low[u] = dfsCounter++;
    s.push_back(u);
    visitedNode[u] = 1;

    for (int i = 0; i < (int)adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (dfs_num[v] == -1) {
            tarjan(v, jumlah);
        }
        if (visitedNode[v] == 1) {
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        }
    }

    if (dfs_num[u] == dfs_low[u]) {
        while (true) {
            int node = s.back();
            s.pop_back();
            visitedNode[node] = -1;

            jumlah++;

            if (node == u) {
                jumlahs.push_back(jumlah);

                break;
            }
        }
    }
}

vector<int> jumlahs;

int main() {
    int n;
    cin >> n;

    adjList.assign(n, vector<int>());
    dfs_num.assign(n, -1);
    dfs_low.assign(n, 0);
    visitedNode.assign(n, -1);

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];

        adjList[i].push_back(p[i] - 1);
    }
    dfsCounter = numSCC = 0;

    for (int i = 0; i < n; i++) {
        if (dfs_num[i] == -1) {
            int jumlah = 0;
            tarjan(i, jumlah);
        }
    }

    sort(jumlahs.begin(), jumlahs.end());

    int join = 0;
    bool can_join = false;

    for (int i = 0; i < 2; i++) {
        join += jumlahs.back();
        jumlahs.pop_back();

        if (jumlahs.empty()) {
            can_join = true;
            jumlahs.push_back(join);

            break;
        }
    }

    if (!can_join) {
        jumlahs.push_back(join);
    }

    long long result = 0;
    for (int i = 0; i < (int)jumlahs.size(); i++) {
        result += (1LL * jumlahs[i] * jumlahs[i]);
    }
    cout << result << '\n';
}
