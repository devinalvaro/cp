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
    vector<vector<int>> g(5, vector<int>(5));
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> g[i][j];
        }
    }

    vector<int> order = {0, 1, 2, 3, 4};
    long long best = INT_MIN;
    do {
        long long sum = 0;
        sum += 2 * (g[order[4]][order[3]] + g[order[3]][order[4]]);
        sum += 2 * (g[order[0]][order[4]] + g[order[4]][order[0]]);
        sum += g[order[1]][order[2]] + g[order[2]][order[1]];
        sum += g[order[0]][order[2]] + g[order[2]][order[0]];

        best = max(best, sum);
    } while (next_permutation(order.begin(), order.end()));

    cout << best << endl;
}
