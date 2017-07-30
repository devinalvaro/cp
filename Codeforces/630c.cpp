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

int main() {
    int n;
    cin >> n;

    vector<long long> dp(n + 1);
    dp[1] = 2;
    for (int i = 2; i <= n; i++) {
        dp[i] = (dp[i - 1] + 1) * 2;
    }

    cout << dp[n] << endl;
}
