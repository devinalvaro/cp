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
    int n, l;
    cin >> n >> l;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    double min_dist = INT_MIN;
    for (int i = 0; i < n - 1; i++) {
        min_dist = max(min_dist, ((double)a[i + 1] - (double)a[i]) / (double)2);
    }

    min_dist = max(min_dist, (double)a[0]);
    min_dist = max(min_dist, (double)l - (double)a[n - 1]);

    cout << fixed << setprecision(10) << min_dist << endl;
}
