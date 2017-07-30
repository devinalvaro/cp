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

const long long MOD = 1000000007;

int main()
{
    int t, k;
    cin >> t >> k;

    vector<long long> memo(100001, 1);
    for (int i = k; i <= 100000; i++) {
        memo[i] = ((memo[i - 1] % MOD) + (memo[i - k] % MOD) % MOD);
    }

    vector<long long> ans(100001, 0);
    for (int i = 1; i <= 100000; i++) {
        ans[i] = ((ans[i - 1] % MOD) + (memo[i] % MOD)) % MOD;
    }

    int a, b;
    for (int i = 0; i < t; i++) {
        cin >> a >> b;

        long long result = ((ans[b] % MOD) - (ans[a - 1] % MOD)) % MOD;
        if (result < 0)
            result += MOD;

        cout << result % MOD << endl;
    }
}
