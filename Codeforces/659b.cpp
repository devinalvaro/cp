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

int main()
{
    long long n, m;
    cin >> n >> m;

    string name;
    long long region, score;
    vector<vector<pair<long long, string>>> participants(
        m, vector<pair<long long, string>>());
    for (long long i = 0; i < n; i++) {
        cin >> name >> region >> score;
        participants[region - 1].push_back(
            pair<long long, string>(score, name));
    }

    for (long long i = 0; i < m; i++) {
        sort(participants[i].rbegin(), participants[i].rend());

        if ((int)participants[i].size() == 2) {
            cout << participants[i][0].second << ' '
                 << participants[i][1].second << endl;
        } else {
            if (participants[i][1].first == participants[i][2].first) {
                cout << "?" << endl;
            } else {
                cout << participants[i][0].second << ' '
                     << participants[i][1].second << endl;
            }
        }
    }
}
