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

int main() {
    int n, m;

    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        
        if (i > 0)
            a[i] += a[i - 1];
    }

    cin >> m;
    int q;
    for (int i = 0; i < m; i++) {
        cin >> q;

        vector<int>::iterator f = lower_bound(a.begin(), a.end(), q);
        cout << f - a.begin() + 1 << endl;
    }
}
