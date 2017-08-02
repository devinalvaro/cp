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

    int n;
    cin >> n;

    vector<long long> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    string s;
    vector<pair<string, string>> strings(n);
    for (int i = 0; i < n; i++) {
        cin >> s;
        strings[i].first = s;
        reverse(s.begin(), s.end());
        strings[i].second = s;
    }

    vector<vector<long long>> energy(n, vector<long long>(2, LLONG_MAX));
    energy[0][0] = 0;
    energy[0][1] = c[0];
    for (int i = 1; i < n; i++) {
        if (strings[i].first >= strings[i - 1].first) {
            energy[i][0] = min(energy[i][0], energy[i - 1][0]);
        }
        if (strings[i].first >= strings[i - 1].second) {
            energy[i][0] = min(energy[i][0], energy[i - 1][1]);
        }

        if (energy[i - 1][0] != LLONG_MAX &&
            strings[i].second >= strings[i - 1].first) {
            energy[i][1] = min(energy[i][1], energy[i - 1][0] + c[i]);
        }
        if (energy[i - 1][1] != LLONG_MAX &&
            strings[i].second >= strings[i - 1].second) {
            energy[i][1] = min(energy[i][1], energy[i - 1][1] + c[i]);
        }
    }

    if (min(energy[n - 1][0], energy[n - 1][1]) == LLONG_MAX) {
        cout << -1 << '\n';
    } else {
        cout << min(energy[n - 1][0], energy[n - 1][1]) << '\n';
    }
}
