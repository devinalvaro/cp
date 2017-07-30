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

const int MOD = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    vector<int> s(n), e(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i] >> e[i];
    }

    vector<int> parties(n, 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (e[j] < s[i]) {
                parties[i] += (parties[j] % MOD);
                parties[i] %= MOD;
            }
        }
    }

    for (int j = 0; j < n; j++) {
        cout << j << ' ' << parties[j] << '\n';
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += (parties[i] % MOD);
        sum %= MOD;
    }

    cout << sum << '\n';
}
