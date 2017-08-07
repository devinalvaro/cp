/* graph : sssp (dijkstra) */

#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

int main()
{
    int tc;
    int n, m, s, t, p;
    int u, v, c;
    map<int, vector<ii>> adj, adjRev;

    cin >> tc;

    while (tc--) {
        cin >> n >> m >> s >> t >> p;

        int weight[n + 1][n + 1];

        for (int i = 0; i < n + 1; i++) {
            for (int j = 0; j < n + 1; j++) {
                weight[i][j] = 10e5;
            }
        }

        adj.clear();
        adjRev.clear();

        for (int i = 0; i < m; i++) {
            cin >> u >> v >> c;

            weight[u][v] = c;
            adj[u].push_back(ii(c, v));
            adjRev[v].push_back(ii(c, u));
        }

        vi distSource(n + 1, 10e5);
        distSource[s] = 0;

        priority_queue<ii, vector<ii>, greater<ii>> pq;
        pq.push(ii(0, s));

        while (!pq.empty()) {
            ii front = pq.top();
            pq.pop();

            int d = front.first;
            int u = front.second;

            if (d > distSource[u])
                continue;

            for (int j = 0; j < (int)adj[u].size(); j++) {
                ii v = adj[u][j];

                if (distSource[u] + v.first < distSource[v.second]) {
                    distSource[v.second] = distSource[u] + v.first;
                    pq.push(ii(distSource[v.second], v.second));
                }
            }
        }

        vi distDest(n + 1, 10e5);
        distDest[t] = 0;

        pq.push(ii(0, t));

        while (!pq.empty()) {
            ii front = pq.top();
            pq.pop();

            int d = front.first;
            int u = front.second;

            if (d > distDest[u])
                continue;

            for (int j = 0; j < (int)adjRev[u].size(); j++) {
                ii v = adjRev[u][j];

                if (distDest[u] + v.first < distDest[v.second]) {
                    distDest[v.second] = distDest[u] + v.first;
                    pq.push(ii(distDest[v.second], v.second));
                }
            }
        }

        int result = -1;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (distSource[i] + weight[i][j] + distDest[j] <= p) {
                    /* cout << "u: " << i << ' ' << "v: " << j << '\n'; */
                    /* cout << "distSource[u]: " << distSource[i] << '\n'; */
                    /* cout << "weight[u][v]: " << weight[i][j] << '\n'; */
                    /* cout << "distDest[v]: " << distDest[j] << '\n'; */
                    /* cout << "= " << distSource[i] + weight[i][j] +
                     * (distSource[t] - distSource[j]) << '\n'; */
                    /* cout << '\n'; */

                    result = max(result, weight[i][j]);
                }
            }
        }

        cout << result << '\n';
    }
}
