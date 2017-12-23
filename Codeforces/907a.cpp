#include <bits/stdc++.h>

using namespace std;

int main() {
    int v1, v2, v3, m;
    cin >> v1 >> v2 >> v3 >> m;

    for (int i = v1; i <= 2 * v1; i++) {
        for (int j = v2; j <= 2 * v2; j++) {
            for (int k = v3; k <= 2 * v3; k++) {
                if ((i > j && j > k) && ((2 * m) < i) && ((2 * m) < j) &&
                    (m <= k && k <= (2 * m))) {
                    cout << i << '\n';
                    cout << j << '\n';
                    cout << k << '\n';

                    return 0;
                }
            }
        }
    }

    cout << -1 << '\n';

    return 0;
}
