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
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int i;
    for (i = 0; i < n; i++) {
        if (a[i] <= 0 || a[i] < a[k - 1]) {
            break;
        }
    }

    cout << i << endl;
}
