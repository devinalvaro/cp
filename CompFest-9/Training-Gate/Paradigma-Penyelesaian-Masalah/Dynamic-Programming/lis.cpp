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

    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<long long> lis(n, 1), lis_count(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i]) {
                lis[i] = max(lis[i], lis[j] + 1);
            }
        }

        if (lis[i] == 1) {
            lis_count[i] = 1;

            continue;
        }

        for (int j = 0; j < i; j++) {
            if (a[j] < a[i] && lis[j] == lis[i] - 1) {
                lis_count[i] += lis_count[j];
            }
        }
    }

    long long lis_ways = 0, lis_len = *max_element(lis.begin(), lis.end());
    for (int i = 0; i < n; i++) {
        if (lis[i] == lis_len) {
            lis_ways += lis_count[i];
        }
    }

    cout << lis_len << ' ' << lis_ways << '\n';
}
