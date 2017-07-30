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

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    int i = 1, j = 0;
    vector<int> b;
    while (i <= 1000000000) {
        if (j < n && i == a[j]) {
            i++;
            j++;

            continue;
        }

        m -= i;

        if (m < 0) {
            break;
        }

        b.push_back(i++);
    }

    cout << (int)b.size() << endl;
    for (int i = 0; i < (int)b.size(); i++) {
        cout << (i == 0 ? "" : " ") << b[i];
    }
    cout << endl;
}
