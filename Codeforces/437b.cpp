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

int lowbit(int n)
{
    return (n & -n);
}

int main()
{
    ios_base::sync_with_stdio(0);

    int sum, limit;
    cin >> sum >> limit;

    vector<pair<int, int>> lowbits(limit + 1);
    for (int i = 1; i <= limit; i++) {
        lowbits[i].first = lowbit(i);
        lowbits[i].second = i;
    }

    sort(lowbits.begin(), lowbits.end());

    vector<int> S;
    for (int i = limit; i >= 1; i--) {
        if (lowbits[i].first <= sum) {
            sum -= lowbits[i].first;

            S.push_back(lowbits[i].second);
        }
    }

    if (sum == 0) {
        cout << (int)S.size() << '\n';
        for (int i = 0; i < (int)S.size(); i++) {
            cout << S[i] << (i == (int)S.size() - 1 ? '\n' : ' ');
        }
    } else {
        cout << -1 << '\n';
    }
}
