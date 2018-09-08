/* Prime Path */

#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<bool> is_prime(10000, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i < 10000; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j < 10000; j += i) {
                is_prime[j] = false;
            }
        }
    }

    map<int, vector<int>> edges;

    vector<int> primes;
    for (int i = 1000; i < 10000; i++) {
        if (is_prime[i]) {
            // 1
            int temp = i - (i % 10);
            for (int j = temp; j < temp + 10; j++) {
                if (j != i && is_prime[j]) {
                    edges[i].push_back(j);
                }
            }

            // 2
            temp = i - (i % 100) + (i % 10);
            for (int j = temp; j < temp + 100; j += 10) {
                if (j != i && is_prime[j]) {
                    edges[i].push_back(j);
                }
            }

            // 3
            temp = i - (i % 1000) + (i % 100);
            for (int j = temp; j < temp + 1000; j += 100) {
                if (j != i && is_prime[j]) {
                    edges[i].push_back(j);
                }
            }

            // 4
            temp = i - ((i / 1000) * 1000);
            for (int j = temp; j < temp + 10000; j += 1000) {
                if (j != i && is_prime[j]) {
                    edges[i].push_back(j);
                }
            }
        }
    }

    int t;
    scanf("%d", &t);

    while (t--) {
        int a, b;
        scanf("%d %d", &a, &b);

        vector<bool> visited(10000, false);
        visited[a] = true;
        vector<int> dist(10000, INT_MAX);
        dist[a] = 0;

        queue<int> q;
        q.push(a);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int j = 0; j < (int)edges[u].size(); j++) {
                int v = edges[u][j];

                if (!visited[v]) {
                    visited[v] = true;
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }

        if (dist[b] == INT_MAX)
            printf("Impossible\n");
        else
            printf("%d\n", dist[b]);
    }

    return 0;
}
