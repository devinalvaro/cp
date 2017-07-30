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

bool comp(const pair<int, int>& a, const pair<int, int>& b)
{
    return (a.first == b.first ? a.second > b.second : a.first < b.first);
}

int main()
{
    ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> monyet(n);
    for (int i = 0; i < n; i++) {
        cin >> monyet[i].first >> monyet[i].second;
    }

    sort(monyet.begin(), monyet.end(), comp);

    int right = 0;
    int recruited = 0;
    for (int i = 0; i < n; i++) {
        if (monyet[i].first > right + 1) {
            recruited = -1;

            break;
        }
        if (monyet[i].second <= right) {
            continue;
        }

        int best_right = INT_MIN;
        for (int j = i; j < n; j++) {
            if (monyet[j].first > right + 1) {
                break;
            }

            best_right = max(best_right, monyet[j].second);

            i = j;
        }

        right = best_right;
        recruited++;
    }

    if (right >= m)
        cout << recruited << '\n';
    else
        cout << -1 << '\n';
}
