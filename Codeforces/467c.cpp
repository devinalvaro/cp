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

    int n, m, k;
    cin >> n >> m >> k;

    long long temp;
    vector<long long> p(n);
    for (int i = 0; i < n; i++) {
        cin >> temp;
        p[i] = (i == 0 ? 0 : p[i - 1]) + temp;
    }

    vector<vector<long long>> val(n, vector<long long>(k));
    for (int i = 0; i < k; i++) {
        val[m - 1][i] = p[m - 1];
    }
    for (int i = m; i < n; i++) {
        for (int j = 0; j < k; j++) {
            val[i][j] = val[i - 1][j];

            long long candidate
                = (j == 0 ? 0 : val[i - m][j - 1]) + (p[i] - p[i - m]);
            if (candidate > val[i][j]) {
                val[i][j] = candidate;
            }
        }
    }

    cout << val[n - 1][k - 1] << '\n';
}
