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

    vector<pair<int, int>> teams(n);
    for (int i = 0; i < n; i++) {
        cin >> teams[i].first >> teams[i].second;
    }

    int total = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                continue;

            if (teams[i].first == teams[j].second)
                total++;
        }
    }
    cout << total << endl;
}
