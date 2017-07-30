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

const long long MOD = 1000000007;

int main()
{
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    vector<long long> ways(2), prev_ways(2);
    ways[1] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            prev_ways[j] = ways[j];
            ways[j] = 0;
        }

        ways[0] += (2 * prev_ways[0]) % MOD;
        ways[0] += prev_ways[1] % MOD;
        ways[0] %= MOD;

        ways[1] += (3 * prev_ways[0]) % MOD;
        ways[1] %= MOD;
    }

    cout << ways[1] << '\n';
}
