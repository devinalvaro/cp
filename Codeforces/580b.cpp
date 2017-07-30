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

int main() {
    int n, d;
    cin >> n >> d;

    vector<pair<int, int>> friends(n);
    for (int i = 0; i < n; i++) {
        cin >> friends[i].first >> friends[i].second;
    }

    sort(friends.begin(), friends.end());

    int j = 1;
    long long sum = friends[0].second, result = sum;

    for (int i = 0; i < n; i++) {
        while (j < n && friends[j].first - friends[i].first < d) {
            sum += friends[j].second;

            j++;
        }

        result = max(result, sum);

        sum -= friends[i].second;
    }

    cout << result << endl;
}
