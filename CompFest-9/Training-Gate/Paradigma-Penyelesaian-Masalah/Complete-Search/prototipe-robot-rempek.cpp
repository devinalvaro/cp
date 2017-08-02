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

    int n, m, k, q;
    cin >> n >> m >> k >> q;

    vector<vector<char>> petak(n, vector<char>(m));
    vector<pair<int, int>> belida;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> petak[i][j];

            if (petak[i][j] == 'X') {
                belida.push_back(pair<int, int>(i, j));
            }
        }
    }

    for (int i = 0; i < q; i++) {
        int r, c;
        cin >> r >> c;
        r--;
        c--;

        int min_dist = INT_MAX;
        for (int j = 0; j < (int)belida.size(); j++) {
            min_dist = min(min_dist, abs(r - belida[j].first) +
                                         abs(c - belida[j].second));
        }

        cout << min_dist << '\n';
    }
}
