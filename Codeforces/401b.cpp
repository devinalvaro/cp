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
    int x, k;
    cin >> x >> k;

    vector<bool> r(x);
    for (int i = 0; i < k; i++) {
        int id, num2, num1;

        cin >> id;
        if (id == 1) {
            cin >> num2 >> num1;
            r[num2] = true;
            r[num1] = true;
        } else {
            cin >> num2;
            r[num2] = true;
        }
    }

    vector<int> m;
    for (int i = 1; i < x; i++) {
        if (!r[i]) {
            m.push_back(i);
        }
    }

    int max_num = (int)m.size();
    int min_num = 0;
    for (int i = 0; i < (int)m.size();) {
        min_num += 1;

        if (i < (int)m.size() - 1 && m[i] + 1 == m[i + 1]) {
            i += 2;
        } else {
            i++;
        }
    }

    cout << min_num << ' ' << max_num << endl;
}
