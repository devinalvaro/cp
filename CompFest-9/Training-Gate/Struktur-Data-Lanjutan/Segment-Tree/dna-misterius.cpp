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

class SegmentTree
{
private:
    size_t n;
    string s;
    vector<pair<int, int>> segment_tree; // first: sum, second: minsum

    int left_child(int parent) { return (parent << 1) + 1; }

    int right_child(int parent) { return (parent << 1) + 2; }

    int mid(int left, int right) { return (left + right) >> 1; }

    void build(int parent, int left, int right)
    {
        if (left == right) {
            segment_tree[parent].first = segment_tree[parent].second =
                (s[left] == '(' ? 1 : -1);

            return;
        }

        build(left_child(parent), left, mid(left, right));
        build(right_child(parent), mid(left, right) + 1, right);

        segment_tree[parent].first = segment_tree[left_child(parent)].first +
                                     segment_tree[right_child(parent)].first;
        segment_tree[parent].second =
            min(segment_tree[left_child(parent)].second,
                segment_tree[left_child(parent)].first +
                    segment_tree[right_child(parent)].second);
    }

    void update(int parent, int left, int right, int k)
    {
        if (left == right) {
            segment_tree[parent].first = segment_tree[parent].second =
                -segment_tree[parent].first;

            return;
        }

        if (k <= mid(left, right)) {
            update(left_child(parent), left, mid(left, right), k);
        } else {
            update(right_child(parent), mid(left, right) + 1, right, k);
        }

        segment_tree[parent].first = segment_tree[left_child(parent)].first +
                                     segment_tree[right_child(parent)].first;
        segment_tree[parent].second =
            min(segment_tree[left_child(parent)].second,
                segment_tree[left_child(parent)].first +
                    segment_tree[right_child(parent)].second);
    }

public:
    SegmentTree(string _s)
    {
        s = _s;
        n = s.size();

        segment_tree.assign(4 * n, pair<int, int>(0, 0));
        build(0, 0, n - 1);
    }

    void update(int k) { update(0, 0, n - 1, k); }

    bool is_balanced()
    {
        return segment_tree[0].first == 0 && segment_tree[0].second == 0;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        SegmentTree st(s);

        int c;
        while (cin >> c) {
            if (c == -1)
                break;

            if (c == 0) {
                if (st.is_balanced()) {
                    cout << 'Y';
                } else {
                    cout << 'T';
                }
            } else if (c == 1) {
                int k;
                cin >> k;

                s[k] = (s[k] == '(' ? ')' : '(');
                st.update(k);
            }
        }
        cout << '\n';
    }
}
