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

const int N = 100000;

class SegmentTree
{
private:
    int n;
    vector<long long> arr;
    vector<long long> segment_tree;
    vector<long long> lazy;

    int left_child(int parent) { return (parent << 1) + 1; }

    int right_child(int parent) { return (parent << 1) + 2; }

    void build(int parent, int left, int right)
    {
        if (left > right)
            return;

        if (left == right) {
            segment_tree[parent] = arr[left];

            return;
        }

        int mid = (left + right) / 2;
        build(left_child(parent), left, mid);
        build(right_child(parent), mid + 1, right);

        segment_tree[parent] = segment_tree[left_child(parent)] +
                               segment_tree[right_child(parent)];
    }

    long long get_sum(int parent, int left, int right, int i, int j)
    {
        if (lazy[parent] != 0) {
            segment_tree[parent] += (right - left + 1) * lazy[parent];

            if (left != right) {
                lazy[left_child(parent)] += lazy[parent];
                lazy[right_child(parent)] += lazy[parent];
            }

            lazy[parent] = 0;
        }

        if (left > right || left > j || right < i)
            return 0;

        if (left >= i && right <= j) {
            return segment_tree[parent];
        }

        int mid = (left + right) / 2;
        return get_sum(left_child(parent), left, mid, i, j) +
               get_sum(right_child(parent), mid + 1, right, i, j);
    }

    void update_range(int parent, int left, int right, int i, int j, int y)
    {
        if (lazy[parent] != 0) {
            segment_tree[parent] += (right - left + 1) * lazy[parent];

            if (left != right) {
                lazy[left_child(parent)] += lazy[parent];
                lazy[right_child(parent)] += lazy[parent];
            }

            lazy[parent] = 0;
        }

        if (left > right || left > j || right < i)
            return;

        if (left >= i && right <= j) {
            segment_tree[parent] += (right - left + 1) * y;

            if (left != right) {
                lazy[left_child(parent)] += y;
                lazy[right_child(parent)] += y;
            }

            return;
        }

        int mid = (left + right) / 2;
        update_range(left_child(parent), left, mid, i, j, y);
        update_range(right_child(parent), mid + 1, right, i, j, y);

        segment_tree[parent] = segment_tree[left_child(parent)] +
                               segment_tree[right_child(parent)];
    }

public:
    SegmentTree(int _n, vector<long long> &_arr)
    {
        n = _n;
        arr = _arr;

        segment_tree.assign(4 * n, 0);
        build(0, 0, n - 1);

        lazy.assign(4 * n, 0);
    }

    long long get_sum(int i, int j) { return get_sum(0, 0, n - 1, i, j); }

    void update_range(int i, int j, int y)
    {
        update_range(0, 0, n - 1, i, j, y);
    }
};

int main()
{
    ios_base::sync_with_stdio(0);

    int t;
    while (cin >> t) {
        if (t == 0)
            break;

        vector<long long> arr(N, 0);
        SegmentTree st(N, arr);

        while (t--) {
            char c;
            cin >> c;

            int a, b, y;
            if (c == 'B') {
                cin >> a >> b >> y;
                a--;
                b--;

                st.update_range(a, b, y);
            } else if (c == 'Q') {
                cin >> a;
                a--;

                cout << st.get_sum(a, a) << '\n';
            }
        }
    }
}
