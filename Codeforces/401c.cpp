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
    int n, m;
    cin >> n >> m;

    if (m < n - 1) {
        cout << -1 << endl;

        return 0;
    }
    if (m > 2 + (2 * n)) {
        cout << -1 << endl;

        return 0;
    }

    int single_zero = 0; // 0
    int single_one = 0; // 1
    int duo = 0; // 10
    int triple = 0; // 110

    if (n > m) {
        single_zero = n - m;
        n -= single_zero;
    }

    /* cout << n << ' ' << m << endl; */

    if (n > m / 2) {
        duo = min((n - (m / 2)) * 2, min(n, m));
        n -= duo;
        m -= duo;
    }

    /* cout << n << ' ' << m << endl; */

    triple = min(n, m / 2);
    n -= triple;
    m -= 2 * triple;

    /* cout << n << ' ' << m << endl; */

    single_one = m;

    for (int i = 0; i < single_zero; i++) {
        cout << "0";
    }
    for (int i = 0; i < triple; i++) {
        cout << "110";
    }
    for (int i = 0; i < duo; i++) {
        cout << "10";
    }
    for (int i = 0; i < single_one; i++) {
        cout << "1";
    }

    cout << endl;
}
