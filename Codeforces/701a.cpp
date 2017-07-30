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

    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        a[i].second = i + 1;
        cin >> a[i].first;
    }

    sort(a.begin(), a.end());

    for (int i = 0; i < n / 2; i++) {
        cout << a[i].second << ' ' << a[n - 1 - i].second << '\n';
    }
}
