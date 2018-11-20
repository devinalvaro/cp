/* Can you solve these queries I */

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

const int N = 5e5 + 7;

int a[N];

struct Node {
    int best;
    int prefixBest;
    int suffixBest;
    int sum;

    Node() {
        best = prefixBest = suffixBest = sum = 0;
    }

    Node(int val) {
        best = prefixBest = suffixBest = sum = val;
    }

    Node(Node left, Node right) {
        best =
            max(max(left.best, right.best), left.suffixBest + right.prefixBest);
        prefixBest = max(left.prefixBest, left.sum + right.prefixBest);
        suffixBest = max(right.suffixBest, right.sum + left.suffixBest);
        sum = left.sum + right.sum;
    }
} st[4 * N];

Node left_child(int id) {
    return st[(2 * id) + 1];
}

Node right_child(int id) {
    return st[(2 * id) + 2];
}

void build(int id, int l, int r) {
    if (l > r) {
        return;
    }
    if (l == r) {
        st[id] = Node(a[l]);
        return;
    }

    int m = (l + r) / 2;
    build((2 * id) + 1, l, m);
    build((2 * id) + 2, m + 1, r);

    st[id] = Node(left_child(id), right_child(id));
}

Node query(int id, int l, int r, int p, int q) {
    if (l > r || l > q || r < p) {
        Node node(-1e9);
        node.sum = 0;
        return node;
    }
    if (l >= p && r <= q) {
        return st[id];
    }

    int m = (l + r) / 2;
    Node left_query = query((2 * id) + 1, l, m, p, q);
    Node right_query = query((2 * id) + 2, m + 1, r, p, q);

    return Node(left_query, right_query);
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    build(0, 0, n - 1);

    int q;
    scanf("%d", &q);
    while (q--) {
        int p, q;
        scanf("%d %d", &p, &q);

        Node node = query(0, 0, n - 1, p - 1, q - 1);
        printf("%d\n", node.best);
    }

    return 0;
}
