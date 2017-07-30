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
    long long n;
    cin >> n;

    if (n <= 2) {
        cout << -1 << endl;
    } else if (n & 1) {
        cout << ((n * n) - 1) / 2 << ' ' << ((n * n) + 1) / 2 << endl;
    } else {
        cout << ((n * n / 4) - 1) << ' ' << ((n * n / 4) + 1) << endl;
    }
}
