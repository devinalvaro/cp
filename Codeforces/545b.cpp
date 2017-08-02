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

int main()
{
    string s, t;
    cin >> s >> t;

    int n = s.size(), c = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] != t[i]) {
            c++;
        }
    }

    if (c & 1) {
        cout << "impossible" << endl;
        return 0;
    }

    c /= 2;
    string p = s;
    for (int i = 0, j = 0; j < c; i++) {
        if (p[i] != t[i]) {
            p[i] = t[i];
            j++;
        }
    }

    cout << p << endl;
}
