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

long double power(long double x, unsigned int y)
{
    long double result = 1;

    while (y > 0) {
        if (y & 1)
            result = result * x;

        y = y >> 1;
        x *= x;
    }

    return result;
}

int main()
{
    long double n;
    int t;
    cin >> n >> t;

    cout << fixed << setprecision(18) << n * power(1.000000011, t) << endl;
}
