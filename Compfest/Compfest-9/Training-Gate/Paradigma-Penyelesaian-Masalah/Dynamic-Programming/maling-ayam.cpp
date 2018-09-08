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

    vector<int> w(n), c(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> c[i];
    }

    vector<int> value(m + 1);
    for (int j = 0; j <= m; j++) {
        for (int i = 0; i < n; i++) {
            if (w[i] <= j) {
                value[j] = max(value[j], value[j - w[i]] + c[i]);
            }
        }
    }

    cout << value[m] << '\n';
}
