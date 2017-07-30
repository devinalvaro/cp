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

    vector<int> f(n);
    for (int i = 0; i < n; i++) {
        cin >> f[i];
    }

    sort(f.rbegin(), f.rend());

    int time = 0;
    for (int i = 0; i < n; i += k) {
        time += f[i] - 1;
    }

    cout << 2 * time << endl;
}
