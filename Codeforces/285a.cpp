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
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < k; i++) {
        cout << n - i;

        if (i == k - 1 && k == n) {
            cout << '\n';
        } else {
            cout << ' ';
        }
    }
    for (int i = 1; i <= n - k; i++) {
        cout << i << (i == n - k ? '\n' : ' ');
    }
}
