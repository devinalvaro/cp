#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

class SegmentTree {
private:
    size_t n;
    vector<int> t;
    vector<int> segment_tree;

    int left_child(int parent) { return (parent << 1) + 1; }

    int right_child(int parent) { return (parent << 1) + 2; }

    int mid(int left, int right) { return (left + right) >> 1; }

    void build(int parent, int left, int right) {
        if (left == right) {
            segment_tree[parent] = t[left];

            return;
        }

        build(left_child(parent), left, mid(left, right));
        build(right_child(parent), mid(left, right) + 1, right);

        segment_tree[parent] = max(segment_tree[left_child(parent)],
                                   segment_tree[right_child(parent)]);
    }

    int rmq(int parent, int left, int right, int i, int j) {
        if (right < i || left > j)
            return -1;
        if (left >= i && right <= j) {
            return segment_tree[parent];
        }

        return max(rmq(left_child(parent), left, mid(left, right), i, j),
                   rmq(right_child(parent), mid(left, right) + 1, right, i, j));
    }

public:
    SegmentTree(int _n, const vector<int> &_t) {
        n = _n;
        t = _t;

        segment_tree.assign(4 * n, -1);
        build(0, 0, n - 1);
    }

    int rmq(int i, int j) { return rmq(0, 0, n - 1, i, j); }
};

int main() {
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    vector<int> t(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }

    SegmentTree st(n, t);

    int q;
    cin >> q;
    while (q--) {
        int i, j;
        cin >> i >> j;
        i--;
        j--;

        if (t[i] == t[j] && st.rmq(i + 1, j - 1) <= t[i]) {
            cout << "YA\n";
        } else {
            cout << "TIDAK\n";
        }
    }
}
