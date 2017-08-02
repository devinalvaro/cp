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
    cin >> n >> m;

    if (n == 1) {
        cout << 1;
    } else if (n - m > m - 1) {
        cout << m + 1;
    } else {
        cout << m - 1;
    }
    cout << endl;
}
