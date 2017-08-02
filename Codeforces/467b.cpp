#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> x(m + 1);
    for (int i = 0; i < m + 1; i++) {
        cin >> x[i];
    }

    int friends = 0;
    for (int i = 0; i < m; i++) {
        int diff = 0;

        for (int j = 0; j < n; j++) {
            if ((x[i] & (1 << j)) != (x[m] & (1 << j))) {
                diff++;
            }
        }

        if (diff <= k) {
            friends++;
        }
    }

    cout << friends << endl;
}
