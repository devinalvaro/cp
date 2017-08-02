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

bool comp(pair<int, pair<int, int>> &a, pair<int, pair<int, int>> &b)
{
    if (a.first == b.first) {
        if (a.second.first == b.second.first) {
            return a.second.second < b.second.second;
        }
        return a.second.first < b.second.first;
    }
    return a.first < b.first;
}

int main()
{
    int n, k;
    cin >> n >> k;

    vector<pair<int, pair<int, int>>> items(n);
    for (int i = 0; i < n; i++) {
        cin >> items[i].second.first;
    }
    for (int i = 0; i < n; i++) {
        cin >> items[i].second.second;

        items[i].first = items[i].second.first - items[i].second.second;
    }

    sort(items.begin(), items.end(), comp);

    /* for (int i = 0; i < n; i++) { */
    /*     cout << items[i].first << ' ' << items[i].second.first << ' ' */
    /*          << items[i].second.second << endl; */
    /* } */

    long long result = 0;
    for (int i = 0; i < k; i++) {
        result += items[i].second.first;
    }
    for (int i = k; i < n; i++) {
        result += (items[i].first < 0 ? items[i].second.first
                                      : items[i].second.second);
    }
    cout << result << endl;
}
