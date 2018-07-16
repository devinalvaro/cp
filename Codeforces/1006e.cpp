#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define ll long long
#define ve vector
#define pq priority_queue
#define um unordered_map
#define us unordered_set

#define pii pair<int, int>
#define pll pair<ll, ll>

um<int, set<int>> children;
um<int, int> size;

int order = 0;
um<int, int> orders;
um<int, int> orderr;

int dfs(int u) {
    orders[u] = order;
    orderr[order++] = u;

    size[u] = 1;
    for (auto it = children[u].begin(); it != children[u].end(); it++) {
        if (*it != u) {
            size[u] += dfs(*it);
        }
    }
    return size[u];
}

int main() {
    int n, q;
    cin >> n >> q;

    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;

        children[p].insert(i);
    }

    dfs(1);

    while (q--) {
        int u, k;
        cin >> u >> k;

        int order = orders[u];

        if (k > size[u]) {
            cout << -1 << endl;
        } else {
            cout << orderr[order + k - 1] << endl;
        }
    }

    return 0;
}
