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

long long to_decimal(const vector<int> &segment_tree_vector)
{
    long long result = 0;
    for (int i = 0; i < 64; i++) {
        result += ((long long)segment_tree_vector[i] << i);
    }
    return result;
}

class SegmentTree
{
private:
    int n;
    vector<long long> arr;
    vector<vector<int>> segment_tree;
    vector<long long> lazy;

    int left_child(int parent) { return (parent << 1) + 1; }

    int right_child(int parent) { return (parent << 1) + 2; }

    void build(int parent, int left, int right)
    {
        if (left > right)
            return;

        if (left == right) {
            for (int i = 0; i < 64; i++) {
                segment_tree[parent][i] =
                    (arr[left] & ((long long)1 << i) ? 1 : 0);
            }

            return;
        }

        int mid = (left + right) / 2;
        build(left_child(parent), left, mid);
        build(right_child(parent), mid + 1, right);

        for (int i = 0; i < 64; i++) {
            segment_tree[parent][i] = segment_tree[left_child(parent)][i] +
                                      segment_tree[right_child(parent)][i];
        }
    }

    long long get_sum(int parent, int left, int right, int i, int j)
    {
        if (lazy[parent] != 0) {
            for (int i = 0; i < 64; i++) {
                if (lazy[parent] & ((long long)1 << i)) {
                    segment_tree[parent][i] =
                        (right - left + 1) - segment_tree[parent][i];
                }
            }

            if (left != right) {
                lazy[left_child(parent)] ^= lazy[parent];
                lazy[right_child(parent)] ^= lazy[parent];
            }

            lazy[parent] = 0;
        }

        if (left > right || left > j || right < i)
            return 0;

        if (left >= i && right <= j)
            return to_decimal(segment_tree[parent]);

        int mid = (left + right) / 2;
        return get_sum(left_child(parent), left, mid, i, j) +
               get_sum(right_child(parent), mid + 1, right, i, j);
    }

    void update_range(int parent, int left, int right, int i, int j, int b)
    {
        if (lazy[parent] != 0) {
            for (int i = 0; i < 64; i++) {
                if (lazy[parent] & ((long long)1 << i)) {
                    segment_tree[parent][i] =
                        (right - left + 1) - segment_tree[parent][i];
                }
            }

            if (left != right) {
                lazy[left_child(parent)] ^= lazy[parent];
                lazy[right_child(parent)] ^= lazy[parent];
            }

            lazy[parent] = 0;
        }

        if (left > right || left > j || right < i)
            return;

        if (left >= i && right <= j) {
            segment_tree[parent][b] =
                (right - left + 1) - segment_tree[parent][b];

            if (left != right) {
                lazy[left_child(parent)] ^= ((long long)1 << b);
                lazy[right_child(parent)] ^= ((long long)1 << b);
            }

            return;
        }

        int mid = (left + right) / 2;
        update_range(left_child(parent), left, mid, i, j, b);
        update_range(right_child(parent), mid + 1, right, i, j, b);

        for (int i = 0; i < 64; i++) {
            segment_tree[parent][i] = segment_tree[left_child(parent)][i] +
                                      segment_tree[right_child(parent)][i];
        }
    }

public:
    SegmentTree(int _n, vector<long long> &_arr)
    {
        n = _n;
        arr = _arr;

        segment_tree.assign(4 * n, vector<int>(64, 0));
        build(0, 0, n - 1);

        lazy.assign(4 * n, 0);
    }

    long long get_sum(int i, int j) { return get_sum(0, 0, n - 1, i, j); }

    void update_range(int i, int j, int b)
    {
        update_range(0, 0, n - 1, i, j, b);
    }
};

int main()
{
    ios_base::sync_with_stdio(0);

    int n, q;
    cin >> n >> q;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    SegmentTree st(n, a);

    while (q--) {
        int c;
        cin >> c;

        int i, j, b;
        if (c == 1) {
            cin >> i >> j >> b;
            i--;
            j--;

            st.update_range(i, j, b);
        } else if (c == 2) {
            cin >> i >> j;
            i--;
            j--;

            cout << st.get_sum(i, j) << '\n';
        }
    }
}
