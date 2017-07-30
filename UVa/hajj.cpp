#include <algorithm>
#include <bitset>
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

    string s;
    int t = 0;
    while (cin >> s) {
        if (s == "*")
            break;

        cout << "Case " << ++t << ": ";

        if (s == "Hajj") {
            cout << "Hajj-e-Akbar\n";
        } else {
            cout << "Hajj-e-Asghar\n";
        }
    }
}
