#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    int n, l, r, x;
    cin >> n >> l >> r >> x;

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    long long ways = 0;
    for (int mask = 1; mask <= pow(2, n); mask++) {
        int quant = 0;
        int max_number = INT_MIN, min_number = INT_MAX;
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                quant++;
                sum += p[i];

                max_number = max(max_number, p[i]);
                min_number = min(min_number, p[i]);
            }
        }

        if (sum >= l && sum <= r && max_number - min_number >= x) {
            ways++;
        }
    }

    cout << ways << endl;
}
