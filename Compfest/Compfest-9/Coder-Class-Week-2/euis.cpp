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

long long pow2(long long e)
{
    e <<= 1;
    return e % MOD;
}

int main()
{
    ios_base::sync_with_stdio(0);

    string s;
    getline(cin, s);

    long long e = 0, eu = 0;

    size_t f = s.find("e", 0);
    while (f != string::npos) {
        if (f + 1 < s.size() && s[f + 1] == 'u')
            eu++;
        else
            e++;

        f = s.find("e", f + 1);
    }

    long long result = 1;

    while (e--) {
        result <<= 1;
        result %= MOD;
    }
    while (eu--) {
        result *= 3;
        result %= MOD;
    }

    cout << result % MOD << '\n';
}
