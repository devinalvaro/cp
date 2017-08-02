#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

bool comp(const pair<long long, long long> &a,
          const pair<long long, long long> &b)
{
    if (a.first == b.first) {
        return a.first > b.first;
    }
    return a.first < b.first;
}

int main()
{
    long long s, n;
    cin >> s >> n;

    vector<pair<long long, long long>> dragons(n);
    for (int i = 0; i < n; i++) {
        cin >> dragons[i].first >> dragons[i].second;
    }

    sort(dragons.begin(), dragons.end(), comp);

    for (int i = 0; i < n; i++) {
        if (s > dragons[i].first) {
            s += dragons[i].second;
        } else {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}
