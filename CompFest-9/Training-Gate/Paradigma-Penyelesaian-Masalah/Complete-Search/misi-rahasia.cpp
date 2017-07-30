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

int count_one(int bit)
{
    int one = 0;

    while (bit != 0) {
        if (bit & 1) {
            one++;
        }

        bit = bit >> 1;
    }

    return one;
}

int main()
{
    ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    vector<vector<bool>> friends(n, vector<bool>(n));
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        friends[u - 1][v - 1] = true;
        friends[v - 1][u - 1] = true;
    }

    int result = INT_MIN;
    int limit = pow(2, n + 1) - 1;
    for (int bit = 1; bit <= limit; bit++) {
        int member = count_one(bit);
        if (result >= member)
            continue;

        bool valid = true;
        int len = (int)log2(bit) + 1;
        for (int i = 0; i < len && valid; i++) {
            if (!(bit & (1 << i)))
                continue;

            for (int j = 0; j < len; j++) {
                if (i == j || !(bit & (1 << j)))
                    continue;

                if (!friends[i][j]) {
                    valid = false;

                    break;
                }
            }
        }

        if (valid) {
            result = max(result, member);
        }
    }

    cout << result << '\n';
}
