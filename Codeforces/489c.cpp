#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int m, s;
    cin >> m >> s;

    if (s == 0) {
        cout << (m == 1 ? "0 0" : "-1 -1") << endl;
        return 0;
    }

    string memoMin, memoMax;

    for (int i = 0; i < m; i++) {
        int temp = min(s, 9);
        memoMax += temp + '0';
        s -= temp;
    }

    if (s > 0) {
        cout << "-1 -1" << endl;
        return 0;
    }

    for (int i = m - 1; i >= 0; i--) {
        memoMin += memoMax[i];
    }

    int i;
    for (i = 0; memoMin[i] == '0'; i++)
        ;
    memoMin[i]--;
    memoMin[0]++;

    cout << memoMin << ' ' << memoMax << endl;
    return 0;
}
