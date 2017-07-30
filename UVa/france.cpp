/* brute force : iterative */

#include <algorithm>
#include <climits>
#include <iomanip>
#include <iostream>
using namespace std;

int main()
{
    int f, r, ft[1000], rt[1000];
    float d[100000], ans;
    cin >> f;

    while (f != 0) {
        cin >> r;
        int n = 0;

        for (int i = 0; i < f; i++) {
            cin >> ft[i];
        }

        for (int i = 0; i < r; i++) {
            cin >> rt[i];

            for (int j = 0; j < f; j++) {
                d[n++] = rt[i] / (float)ft[j];
            }
        }

        sort(d, d + n);
        ans = INT_MIN;

        for (int i = 1; i < n; i++) {
            ans = max(ans, d[i] / d[i - 1]);
        }

        cout << fixed << setprecision(2) << ans << '\n';
        cin >> f;
    }
}
