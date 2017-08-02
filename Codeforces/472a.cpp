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
    int n;
    cin >> n;

    if (n & 1) {
        cout << 9 << ' ' << n - 9 << endl;
    } else {
        cout << 4 << ' ' << n - 4 << endl;
    }
}
