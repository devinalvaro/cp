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
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    vector<pair<int, int>> c(5);
    for (int i = 0; i < n; i++) {
        c[a[i] - 1].first++;
        c[b[i] - 1].second++;
    }

    int change = 0;
    for (int i = 0; i < 5; i++) {
        if ((c[i].first + c[i].second) % 2 != 0) {
            cout << -1 << endl;

            return 0;
        }

        change
            += ((c[i].first + c[i].second) / 2) - min(c[i].first, c[i].second);
    }

    cout << change / 2 << endl;
}
