/* Unlock the Lock */

#include <bits/stdc++.h>

using namespace std;

int main() {
    int l, u, r, tc = 0;
    while (scanf("%d %d %d", &l, &u, &r)) {
        if (l == 0 && u == 0 && r == 0)
            break;

        vector<int> rv(r);
        for (int i = 0; i < r; i++) {
            scanf("%d", &rv[i]);
        }

        vector<bool> visited(10000, false);
        vector<int> dist(10000, INT_MAX);
        visited[l] = true;
        dist[l] = 0;

        queue<int> q;
        q.push(l);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int i = 0; i < r; i++) {
                int v = (u + rv[i]) % 10000;

                if (!visited[v]) {
                    visited[v] = true;
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }

        if (dist[u] == INT_MAX)
            printf("Case %d: Permanently Locked\n", ++tc);
        else
            printf("Case %d: %d\n", ++tc, dist[u]);
    }

    return 0;
}
