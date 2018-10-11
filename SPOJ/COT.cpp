#include <bits/stdc++.h>

using namespace std;

#define fi  first
#define se  second
#define pb  push_back
#define ll  long long
#define ve  vector
#define pq  priority_queue
#define um  unordered_map
#define us  unordered_set
#define pii pair<int, int>
#define pll pair<ll, ll>

struct Node {
    int cnt;
    Node *left, *right;

    Node(int cnt, Node *left, Node *right) {
        this->cnt = cnt;
        this->left = left;
        this->right = right;
    }

    Node *insert(int l, int r, int k) {
        if (!(l <= k && k <= r)) {
            return this;
        }

        Node *node = new Node(this->cnt + 1, this->left, this->right);
        if (l == r) {
            return node;
        }

        int m = (l + r) / 2;
        node->left = node->left->insert(l, m, k);
        node->right = node->right->insert(m + 1, r, k);
        return node;
    }

    static int query(Node *a, Node *b, Node *c, Node *d, int l, int r, int k) {
        if (l == r) {
            return l;
        }

        int m = (l + r) / 2;
        int cnt = a->left->cnt + b->left->cnt - c->left->cnt - d->left->cnt;
        if (cnt >= k + 1) {
            return query(a->left, b->left, c->left, d->left, l, m, k);
        }
        return query(a->right, b->right, c->right, d->right, m + 1, r, k - cnt);
    }
};

const int N = 111111;
const int LOGN = 19;

int cntr;
int depth[N];
int pa[N][LOGN];
ll a[N];

map<ll, int> M;
um<int, ll> RM;
um<int, ve<int>> adj;

Node *null = new Node(0, NULL, NULL);
Node *roots[N];

void dfs(int u, int p) {
    pa[u][0] = p;
    depth[u] = (p == -1 ? 0 : depth[p] + 1);
    roots[u] = (p == -1 ? null : roots[p])->insert(0, cntr, M[a[u]]);

    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u);
        }
    }
}

int LCA(int u, int v) {
    if (depth[u] < depth[v]) {
        return LCA(v, u);
    }

    int diff = depth[u] - depth[v];
    for (int j = 0; j < LOGN; j++) {
        if ((diff >> j) & 1) {
            u = pa[u][j];
        }
    }

    if (u != v) {
        for (int j = LOGN - 1; j >= 0; j--) {
            if (pa[u][j] != pa[v][j]) {
                u = pa[u][j];
                v = pa[v][j];
            }
        }
        u = pa[u][0];
    }
    return u;
}

int main() {
    memset(pa, -1, sizeof pa);

    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        M[a[i]];
    }

    cntr = 0;
    for (auto it = M.begin(); it != M.end(); it++) {
        M[it->first] = cntr;
        RM[cntr] = it->first;
        cntr++;
    }
    cntr--;

    int u, v, k;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--, v--;

        adj[u].pb(v);
        adj[v].pb(u);
    }

    null->left = null, null->right = null;
    dfs(0, -1);

    for (int j = 1; j < LOGN; j++) {
        for (int i = 0; i < n; i++) {
            int p = pa[i][j - 1];
            if (p != -1) {
                pa[i][j] = pa[p][j - 1];
            }
        }
    }

    while (m--) {
        scanf("%d %d %d", &u, &v, &k);
        u--, v--, k--;

        int lca = LCA(u, v);
        Node *c = roots[lca];
        Node *d = (pa[lca][0] == -1 ? null : roots[pa[lca][0]]);

        int res = Node::query(roots[u], roots[v], c, d, 0, cntr, k);
        printf("%lld\n", RM[res]);
    }

    return 0;
}
