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

bool comp(const pair<long long, long long> &a,
          const pair<long long, long long> &b)
{
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main()
{
    long long n, r, avg;
    cin >> n >> r >> avg;

    vector<pair<long long, long long>> exams(n);
    long long needed = avg * n;
    for (int i = 0; i < n; i++) {
        cin >> exams[i].first >> exams[i].second;

        needed -= exams[i].first;
    }

    sort(exams.begin(), exams.end(), comp);

    long long added = 0, add;

    for (int i = 0; i < n; i++) {
        if (needed <= 0) {
            break;
        }

        add = min(needed, r - exams[i].first);
        needed -= add;
        added += (exams[i].second * add);
    }

    cout << added << endl;
}
