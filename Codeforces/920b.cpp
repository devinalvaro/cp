#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> when(n, 0);

        int current_time = 1;

        for (int i = 0; i < n; i++) {
            int l, r;
            cin >> l >> r;

            if (current_time > r) {
                continue;
            }

            current_time = max(current_time, l);
            when[i] = current_time;

            current_time += 1;
        }

        for (int i = 0; i < n; i++) {
            cout << when[i] << (i == n - 1 ? '\n' : ' ');
        }
    }

    return 0;
}
