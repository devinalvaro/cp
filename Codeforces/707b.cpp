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
    int n, m, k;
    cin >> n >> m >> k;

    if (n == k) {
        cout << -1 << endl;

        return 0;
    }

    vector<pair<int, pair<int, int>>> roads(m, pair<int, pair<int, int>>());
    for (int i = 0; i < m; i++) {
        cin >> roads[i].second.first >> roads[i].second.second
            >> roads[i].first;
    }

    int a;
    vector<bool> isStorage(n, false);
    for (int i = 0; i < k; i++) {
        cin >> a;
        isStorage[a] = true;
    }

    sort(roads.begin(), roads.end());
    for (int i = 0; i < m; i++) {
        int u = roads[i].second.first;
        int v = roads[i].second.second;

        if ((isStorage[u] && !isStorage[v])
            || (!isStorage[u] && isStorage[v])) {
            cout << roads[i].first << endl;

            return 0;
        }
    }

    cout << -1 << endl;
}
