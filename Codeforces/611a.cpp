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
    ios_base::sync_with_stdio(0);

    int x;
    string s;
    cin >> x >> s >> s;

    if (s == "month") {
        if (x <= 29)
            cout << 12 << endl;
        else if (x == 30)
            cout << 11 << endl;
        else
            cout << 7 << endl;
    } else {
        if (x == 5 || x == 6)
            cout << 53;
        else
            cout << 52;
    }
    cout << endl;
}
