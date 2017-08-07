/* brute force : iterative */

#include <iostream>
using namespace std;

int main()
{
    int k, ans[100000][2];

    while (cin >> k) {
        int x = k * 2, y = k * 2, t = 0;
        ans[t][0] = x++;
        ans[t++][1] = y--;

        while (y > k) {
            if ((y * k) % (y - k) == 0) {
                ans[t][0] = (y * k) / (y - k);
                ans[t++][1] = y;
            }

            y--;
        }

        cout << t-- << '\n';

        for (int i = t; i >= 0; i--) {
            cout << "1/" << k << " = 1/" << ans[i][0] << " + 1/" << ans[i][1]
                 << '\n';
        }
    }
}
