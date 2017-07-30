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

int main()
{
    int n;
    cin >> n;

    vector<pair<long long, long long>> schedule(n);
    for (int i = 0; i < n; i++) {
        cin >> schedule[i].first >> schedule[i].second;
    }
    sort(schedule.begin(), schedule.end());

    long long last = LLONG_MIN;
    for (int i = 0; i < n; i++) {
        if (schedule[i].second >= last) {
            last = schedule[i].second;
        } else {
            last = schedule[i].first;
        }
    }
    cout << last << endl;
}
