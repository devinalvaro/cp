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
    int n, k;
    cin >> n >> k;

    vector<int> towers(n);
    for (int i = 0; i < n; i++) {
        cin >> towers[i];
    }

    int step = 0;
    vector<pair<int, int>> result;
    vector<int>::iterator max_tower, min_tower;
    while (step < k) {
        max_tower = max_element(towers.begin(), towers.end());
        min_tower = min_element(towers.begin(), towers.end());

        if (max_tower == min_tower || *max_tower == 0) {
            break;
        }

        /* cout << *max_tower << ' ' << *min_tower << endl; */
        /* cout << stability << endl; */

        result.push_back(pair<int, int>(max_tower - towers.begin(),
                                        min_tower - towers.begin()));

        (*max_tower)--;
        (*min_tower)++;

        max_tower = max_element(towers.begin(), towers.end());
        min_tower = min_element(towers.begin(), towers.end());

        /* cout << *max_tower << ' ' << *min_tower << endl; */
        /* cout << next_stability << endl; */

        step++;
    }

    max_tower = max_element(towers.begin(), towers.end());
    min_tower = min_element(towers.begin(), towers.end());
    int stability = *max_tower - *min_tower;

    cout << stability << ' ' << step << endl;
    for (int i = 0; i < (int)result.size(); i++) {
        cout << result[i].first + 1 << ' ' << result[i].second + 1 << endl;
    }
}
