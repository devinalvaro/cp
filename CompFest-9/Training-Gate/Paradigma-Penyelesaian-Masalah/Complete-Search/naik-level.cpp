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

    int n, m;
    cin >> n >> m;

    vector<int> e(n);
    for (int i = 0; i < n; i++) {
        cin >> e[i];
    }

    int limit = pow(2, n + 1) - 1;
    for (int bit = 1; bit <= limit; bit++) {
        int sum = 0;
        int len = (int)log2(bit) + 1;
        bool valid = true;
        for (int i = 0; i < len && valid; i++) {
            if (!(bit & (1 << i)))
                continue;

            sum += e[i];

            if (sum > m) {
                valid = false;

                break;
            } else if (sum == m) {
                cout << "bisa\n";

                return 0;
            }
        }

        if (valid && sum == m) {
            cout << "bisa\n";

            return 0;
        }
    }

    cout << "tidak bisa\n";
}
