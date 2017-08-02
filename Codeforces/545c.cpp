#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> x(n), h(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> h[i];
    }

    int c = (n == 1 ? 1 : 2);
    for (int i = 1; i < n - 1; i++) {
        if (x[i] - x[i - 1] > h[i]) {
            c++;
        } else if (x[i + 1] - x[i] > h[i]) {
            c++;
            x[i] += h[i];
        }
    }

    cout << c << endl;
}
