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

    vector<bool> rows(n, false), cols(n, false);
    long long rows_occupied = 0, cols_occupied = 0;

    long long cells = (long long)n * (long long)n;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;

        if (!rows[x - 1]) {
            cells -= (n - cols_occupied);
            rows_occupied++;
        }
        if (!cols[y - 1]) {
            cells -= (n - rows_occupied);
            cols_occupied++;
        }

        rows[x - 1] = true;
        cols[y - 1] = true;

        cout << cells << (i == m - 1 ? '\n' : ' ');
    }
}
