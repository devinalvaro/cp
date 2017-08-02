#include <cstring>
#include <iostream>

using namespace std;

int parent[2002];
bool done[2002];

int find(int u) { return parent[u] == u ? u : find(parent[u]); }

void merge(int u, int v) { parent[find(u)] = find(v); }

int main()
{
    for (int i = 0; i < 2002; i++) {
        parent[i] = i;
    }
    memset(done, false, sizeof(done));

    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 0; i + k <= n; i++) {
        for (int j = 0; j < k; j++) {
            merge(i + j, i + k - 1 - j);
        }
    }

    long long ans = 1;
    for (int i = 0; i < n; i++) {
        if (!done[find(i)]) {
            done[find(i)] = true;
            ans = ans * m % (1000000000 + 7);
        }
    }

    cout << ans << endl;
}
