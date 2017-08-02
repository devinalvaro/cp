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
    int a, b;
    cin >> a >> b;

    cout << min(a, b) << ' ' << (max(a, b) - min(a, b)) / 2 << endl;
}
