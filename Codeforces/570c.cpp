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
    int n, m;
    string s;
    cin >> n >> m;
    cin >> s;

    vector<bool> isDot(n, false);
    int dotCount = 0, groupCount = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '.') {
            isDot[i] = true;

            dotCount++;
            if (i == 0 || s[i - 1] != '.') {
                groupCount++;
            }
        }
    }

    while (m--) {
        int x;
        char c;
        cin >> x >> c;
        x--;

        bool wasDot = isDot[x];
        bool willDot = (c == '.');
        s[x] = c;
        isDot[x] = willDot;

        if (wasDot && !willDot) {
            dotCount--;
            if (x > 0 && x < n - 1 && isDot[x - 1] && isDot[x + 1]) {
                groupCount++;
            } else if ((x == 0 || !isDot[x - 1]) &&
                       (x == n - 1 || !isDot[x + 1])) {
                groupCount--;
            }
        } else if (!wasDot && willDot) {
            dotCount++;
            if (x > 0 && x < n - 1 && isDot[x - 1] && isDot[x + 1]) {
                groupCount--;
            } else if ((x == 0 || !isDot[x - 1]) &&
                       (x == n - 1 || !isDot[x + 1])) {
                groupCount++;
            }
        }

        cout << dotCount - groupCount << endl;
    }
}
