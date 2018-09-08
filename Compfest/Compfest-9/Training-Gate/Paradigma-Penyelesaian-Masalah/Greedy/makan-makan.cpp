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

bool comp(const pair<int, int> &a, const pair<int, int> &b)
{
    return (a.second == b.second ? a.first > b.first : a.second < b.second);
}

int main()
{
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    vector<pair<int, int>> pesta(n);
    for (int i = 0; i < n; i++) {
        cin >> pesta[i].first >> pesta[i].second;
    }

    sort(pesta.begin(), pesta.end(), comp);

    int right = 0;
    int datang = 0;
    for (int i = 0; i < n; i++) {
        if (pesta[i].first <= right) {
            continue;
        }

        right = pesta[i].second;
        datang++;
    }

    cout << datang << '\n';
}
