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
    int size;
    Node *left, *right;

    Node(int size, Node *left, Node *right) {
        this->size = size;
        this->left = left;
        this->right = right;
    }

    Node *insert(int l, int r, int p, int d) {
        if (!(l <= p && p <= r)) {
            return this;
        }

        Node *node = new Node(this->size + d, this->left, this->right);
        if (l == r) {
            return node;
        }

        int m = (l + r) / 2;
        node->left = node->left->insert(l, m, p, d);
        node->right = node->right->insert(m + 1, r, p, d);
        return node;
    }

    static int query(Node *a, int l, int r, int lq, int rq) {
        if (l > r || r < lq || rq < l) {
            return 0;
        }
        if (lq <= l && r <= rq) {
            return a->size;
        }

        int m = (l + r) / 2;
        return query(a->left, l, m, lq, rq) + query(a->right, m + 1, r, lq, rq);
    }
};

int main() {
    int n;
    scanf("%d", &n);

    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    Node *null = new Node(0, NULL, NULL);
    null->left = null, null->right = null;

    Node *roots[n];

    um<int, int> last;

    for (int i = 0; i < n; i++) {
        Node *pre = (i == 0 ? null : roots[i - 1]);

        if (last.count(a[i])) {
            pre = pre->insert(0, n - 1, last[a[i]], -1);
        }
        last[a[i]] = i;

        roots[i] = pre->insert(0, n - 1, i, +1);
    }

    int m;
    scanf("%d", &m);

    while (m--) {
        int lq, rq;
        scanf("%d %d", &lq, &rq);
        lq--, rq--;

        printf("%d\n", Node::query(roots[rq], 0, n -1, lq, rq));
    }
}
