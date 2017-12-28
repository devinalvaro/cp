#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    int min_num = INT_MAX;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];

        min_num = min(min_num, a[i]);
    }

    int min_dist = INT_MAX;
    int last_place = -1;

    for (int i = 0; i < n; i++) {
        if (a[i] == min_num) {
            if (last_place != -1) {
                min_dist = min(min_dist, i - last_place);
            }

            last_place = i;
        }
    }

    cout << min_dist << '\n';

    return 0;
}
