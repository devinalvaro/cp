#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        map<int, vector<pair<int, int>>> adjacent;

        while (m--) {
            int x, y, r;
            cin >> x >> y >> r;

            adjacent[x - 1].push_back(make_pair(r, y - 1));
            adjacent[y - 1].push_back(make_pair(r, x - 1));
        }

        int s;
        cin >> s;
        s--;

        vector<int> dist(n, INT_MAX);
        dist[s] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        pq.push(make_pair(dist[s], s));

        while (!pq.empty()) {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (d > dist[u])
                continue;

            for (int j = 0; j < (int)adjacent[u].size(); j++) {
                int d = adjacent[u][j].first;
                int v = adjacent[u][j].second;

                if (dist[u] + d < dist[v]) {
                    dist[v] = dist[u] + d;

                    pq.push(make_pair(dist[v], v));
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (i == s) {
                if (s == n - 1) {
                    cout << '\n';
                }

                continue;
            }

            if (dist[i] == INT_MAX) {
                cout << -1;
            } else {
                cout << dist[i];
            }
            cout << (i == n - 1 ? '\n' : ' ');
        }
    }
}
