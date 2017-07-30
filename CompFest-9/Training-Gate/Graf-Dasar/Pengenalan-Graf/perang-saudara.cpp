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

    vector<vector<bool>> edges(n, vector<bool>(n));
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        edges[u - 1][v - 1] = true;
        edges[v - 1][u - 1] = true;
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;

        int cities = 0;
        for (int j = 0; j < n; j++) {
            if (edges[j][a - 1] && edges[j][b - 1]) {
                cities++;
            }
        }
        cout << cities << '\n';
    }
}
