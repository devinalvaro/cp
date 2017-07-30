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
    int a, b, c;
    cin >> a >> b >> c;

    int best = INT_MIN;

    best = max(best, a + b + c);
    best = max(best, a + b * c);
    best = max(best, a * b + c);
    best = max(best, a * b * c);
    best = max(best, a * (b + c));
    best = max(best, (a + b) * c);

    cout << best << endl;
}
