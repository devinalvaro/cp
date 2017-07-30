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

int main()
{
    ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int cost = 0;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;

        cost += (v[x - 1] < v[y - 1] ? v[x - 1] : v[y - 1]);
    }

    cout << cost << '\n';
}
