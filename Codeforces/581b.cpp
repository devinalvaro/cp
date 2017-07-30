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
    int n;
    cin >> n;

    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    int maxi = h[n - 1];
    vector<int> m(n);
    for (int i = n - 2; i >= 0; i--) {
        m[i] = maxi;

        maxi = max(maxi, h[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        cout << (h[i] > m[i] ? 0 : m[i] - h[i] + 1) << ' ';
    }
    cout << 0 << endl;
}
