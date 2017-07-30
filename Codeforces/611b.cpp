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

    long long a, b;
    cin >> a >> b;

    int result = 0;
    long long x = 1;
    for (int i = 1; i <= 60; i++) {
        x = x << 1;

        long long y = 1;
        for (int j = 1; j < i; j++) {
            if (((x - 1) - y) >= a && ((x - 1) - y) <= b)
                result++;

            y = y << 1;
        }
    }

    cout << result << endl;
}
