/* dp : topological sort */

#include <cstring>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

bool visited[110];
map<int, vector<int>> adjList;
vector<int> ts;

void dfs(int u)
{
    visited[u] = true;

    for (int i = 0; i < (int)adjList[u].size(); i++) {
        int v = adjList[u][i];

        if (visited[v] == false) {
            dfs(v);
        }
    }

    ts.push_back(u);
}

int main()
{
    int n, m, i, j;
    cin >> n >> m;

    while (n != 0 || m != 0) {
        memset(visited, false, sizeof(visited));
        adjList.clear();
        ts.clear();

        while (m--) {
            cin >> i >> j;
            adjList[i].push_back(j);
        }

        for (int i = 1; i <= n; i++) {
            if (visited[i] == false) {
                dfs(i);
            }
        }

        for (int i = (int)ts.size() - 1; i > 0; i--) {
            cout << ts[i] << ' ';
        }

        cout << ts[0] << '\n';
        cin >> n >> m;
    }
}
