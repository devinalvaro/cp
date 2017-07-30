/* brute force : iterative */

#include <iostream>
using namespace std;

int main()
{
    int t, n, p, bars[50];
    cin >> t;

    while (t--) {
        cin >> n >> p;

        for (int i = 0; i < p; i++) {
            cin >> bars[i];
        }

        int i;

        for (i = 0; i < (1 << p); i++) {
            int sum = 0;

            for (int j = 0; j < p; j++) {
                if (i & (1 << j)) {
                    sum += bars[j];
                }
            }

            if (sum == n) {
                cout << "YES\n";
                break;
            }
        }

        if (i >= (1 << p)) {
            cout << "NO\n";
        }
    }
}
