#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int n, s, t;
    cin >> n >> s >> t;

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    int pos = s;
    for (int i = 0; i < n; i++) {
        if (pos == t) {
            cout << i << endl;

            return 0;
        }

        pos = p[pos - 1];
    }

    cout << -1 << endl;
}
