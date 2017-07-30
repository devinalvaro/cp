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

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int c = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i - 1]) {
            a[i]++;
            c++;
        } else if (a[i] < a[i - 1]) {
            c += (a[i - 1] - a[i]) + 1;
            a[i] = a[i - 1] + 1;
        }
    }

    cout << c << endl;
}
