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
    int n;
    cin >> n;

    vector<pair<string, string>> names(n);
    string first_name, last_name;
    for (int i = 0; i < n; i++) {

        cin >> first_name >> last_name;
        if (first_name < last_name) {
            names[i].first = first_name;
            names[i].second = last_name;
        } else {
            names[i].first = last_name;
            names[i].second = first_name;
        }
    }

    int id;
    string current_name = "";
    for (int i = 0; i < n; i++) {
        cin >> id;
        id--;

        if (current_name < names[id].first) {
            current_name = names[id].first;

            continue;
        }
        if (current_name < names[id].second) {
            current_name = names[id].second;

            continue;
        }

        cout << "NO" << endl;

        return 0;
    }

    cout << "YES" << endl;
}
