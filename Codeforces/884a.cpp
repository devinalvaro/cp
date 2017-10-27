#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, t;
    cin >> n >> t;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        t -= (86400 - a);

        if (t <= 0) {
            cout << i + 1 << '\n';

            return 0;
        }
    }

    return 0;
}
