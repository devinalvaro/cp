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
    int n, x;
    cin >> n >> x;

    int sum = 0;
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];

        sum += c[i];
    }
    sum = abs(sum);

    cout << sum / x + (sum % x == 0 ? 0 : 1) << endl;
}
