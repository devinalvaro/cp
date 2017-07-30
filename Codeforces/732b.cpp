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

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int c = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] + a[i - 1] < k) {
            c += k - (a[i] + a[i - 1]);
            a[i] += k - (a[i] + a[i - 1]);
        }
    }

    cout << c << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << (i == n - 1 ? '\n' : ' ');
    }
}
