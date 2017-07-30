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

    char c;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> c;
            if (c == 'C' || c == 'M' || c == 'Y') {
                cout << "#Color" << endl;

                return 0;
            }
        }
    }

    cout << "#Black&White" << endl;
}
