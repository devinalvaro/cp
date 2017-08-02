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
    int sum = 0, val;
    for (int i = 0; i < 5; i++) {
        cin >> val;
        sum += val;
    }

    if (sum == 0 || sum % 5 != 0) {
        cout << -1 << endl;
    } else {
        cout << sum / 5 << endl;
    }
}
