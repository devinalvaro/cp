#include <algorithm>
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

map<int, vector<int>> children;

int height(int u)
{
    if (children[u].size() == 0) {
        return 0;
    }

    int node_height = INT_MIN;
    for (int i = 0; i < (int)children[u].size(); i++) {
        int v = children[u][i];

        node_height = max(node_height, height(v));
    }
    return node_height + 1;
}

int leaf(int u)
{
    if (children[u].size() == 0) {
        return 1;
    }

    int leaf_count = 0;
    for (int i = 0; i < (int)children[u].size(); i++) {
        int v = children[u][i];

        leaf_count += leaf(v);
    }
    return leaf_count;
}

int main()
{
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    int p;
    for (int i = 0; i < n - 1; i++) {
        cin >> p;

        children[p - 1].push_back(i + 1);
    }

    cout << leaf(0) << ' ' << height(0) << '\n';
}
