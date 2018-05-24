#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int evens = 0;
vi sizes;
map<int, vi> edges;

void dfs(int u, int p) {
    sizes[u] = 1;

    for (int v : edges[u]) {
        if (v == p) {
            continue;
        }

        dfs(v, u);
        sizes[u] += sizes[v];
    }

    if (sizes[u] % 2 == 0) {
        evens++;
        sizes[u] = 0;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    sizes.assign(n + 1, 0);

    if (n & 1) {
        printf("-1\n");
        return 0;
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        edges[u].pb(v);
        edges[v].pb(u);
    }

    dfs(1, 0);
    printf("%d\n", evens - 1);

    return 0;
}
