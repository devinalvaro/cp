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
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(m, vector<int>(n));
    vector<int> c(n, 0);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }

        int id = distance(a[i].begin(), max_element(a[i].begin(), a[i].end()));
        c[id]++;
    }

    cout << 1 + distance(c.begin(), max_element(c.begin(), c.end())) << endl;
}
