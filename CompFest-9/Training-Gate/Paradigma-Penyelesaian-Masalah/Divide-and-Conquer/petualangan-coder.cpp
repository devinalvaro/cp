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

    long long result = 1, base = 2;
    while (n) {
        if (n & 1) {
            result *= (base % MOD);
            result %= MOD;
        }

        base *= (base % MOD);
        base %= MOD;

        n >>= 1;
    }

    result -= 1;
    result %= MOD;

    if (result <= 0) {
        result += MOD;
    }

    cout << result << '\n';
}
