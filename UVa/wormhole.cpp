/* graph : sssp (negative weight cycle) */

#include <climits>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;

int main()
{
    int c, n, m, x, y, t;
    map<int, vector<ii>> adj;

    cin >> c;

    while (c--) {
        cin >> n >> m;

        adj.clear();

        for (int i = 0; i < m; i++) {
            cin >> x >> y >> t;

            adj[x].push_back(ii(t, y));
        }

        vi dist(n, INT_MAX);
        dist[0] = 0;

        for (int i = 0; i < n - 1; i++) {
            for (int u = 0; u < n; u++) {
                for (int j = 0; j < (int)adj[u].size(); j++) {
                    ii v = adj[u][j];
                    dist[v.second] = min(dist[v.second], dist[u] + v.first);
                }
            }
        }

        bool hasNegativeCycle = false;

        for (int u = 0; u < n; u++) {
            for (int j = 0; j < (int)adj[u].size(); j++) {
                ii v = adj[u][j];

                if (dist[u] + v.first < dist[v.second]) {
                    hasNegativeCycle = true;
                }
            }
        }

        if (hasNegativeCycle) {
            cout << "possible\n";
        } else {
            cout << "not possible\n";
        }
    }
}
