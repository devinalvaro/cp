#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> taps(k);
        for (int i = 0; i < k; i++) {
            cin >> taps[i];
        }

        sort(taps.begin(), taps.end());

        int min_seconds = INT_MIN;
        min_seconds = max(min_seconds, (taps[0] - 1) + 1);
        min_seconds = max(min_seconds, (n - taps[k - 1]) + 1);

        for (int i = 1; i < k; i++) {
            min_seconds = max(min_seconds, ((taps[i] - taps[i - 1]) / 2) + 1);
        }

        cout << min_seconds << '\n';
    }

    return 0;
}
