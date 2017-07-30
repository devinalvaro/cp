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

int main() {
    int n;
    cin >> n;

    vector<vector<int>> m(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> m[i][j];
        }
    }

    int sum = 0;
    vector<int> good_cars;
    for (int i = 0; i < n; i++) {
        bool collide = false;

        for (int  j = 0; j < n; j++) {
            if (m[i][j] == 1 || m[i][j] == 3) {
                collide = true;
                break;
            }
        }

        if (!collide) {
            sum++;
            good_cars.push_back(i + 1);
        }
    }

    cout << sum << endl;
    for (int i = 0; i < (int)good_cars.size(); i++) {
        cout << (i == 0 ? "" : " ") << good_cars[i];
    }
    cout << endl;
}
