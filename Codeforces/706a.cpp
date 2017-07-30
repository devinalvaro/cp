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
    ios_base::sync_with_stdio(0);

    double a, b;
    cin >> a >> b;

    int n;
    cin >> n;

    double result = 1e18;
    for (int i = 0; i < n; i++) {
        double x, y, v;
        cin >> x >> y >> v;

        result = min(result, sqrt(pow(x - a, 2) + pow(y - b, 2)) / v);
    }

    cout << fixed << setprecision(18) << result << endl;
}
