/* graph : bipartite graph check */

#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    int n, l, u, v;
    map<int, vector<int>> adjList;

    while (true) {
        cin >> n;

        if (n == 0) {
            break;
        }

        cin >> l;
        adjList.clear();

        for (int i = 0; i < l; i++) {
            cin >> u >> v;
            adjList[u].push_back(v);
        }

        queue<int> q;
        q.push(0);
        vector<int> color(n, -1);
        color[0] = 0;
        bool isBipartite = true;

        while (!q.empty() && isBipartite) {
            int u = q.front();
            q.pop();

            for (int i = 0; i < (int)adjList[u].size(); i++) {
                int v = adjList[u][i];

                if (color[v] == -1) {
                    color[v] = 1 - color[u];
                    q.push(v);
                } else if (color[v] == color[u]) {
                    isBipartite = false;
                    break;
                }
            }
        }

        if (!isBipartite) {
            cout << "NOT ";
        }

        cout << "BICOLORABLE.\n";
    }
}
