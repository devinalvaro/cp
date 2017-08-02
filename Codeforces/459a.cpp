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
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    if (abs(x2 - x1) != 0 && abs(y2 - y1) != 0 &&
        abs(x2 - x1) != abs(y2 - y1)) {
        cout << -1 << endl;

        return 0;
    }

    int len = max(abs(x2 - x1), abs(y2 - y1));

    int x3, y3, x4, y4;
    x3 = (x1 == x2 ? x1 + len : x1);
    y3 = (y1 == y2 ? y1 + len : y2);
    x4 = (x1 == x2 ? x1 + len : x2);
    y4 = (y1 == y2 ? y1 + len : y1);
    cout << x3 << ' ' << y3 << ' ' << x4 << ' ' << y4 << ' ' << endl;
}
