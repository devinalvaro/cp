#include <climits>
#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int result = 0;
    for (int i = 0; i <= min(n, m / 2); i++) {
        /* cout << "i: " << i << endl; */
        /* cout << "(n - i) / 2: " << (n - i) / 2 << endl; */
        /* cout << "m - (2 * i): " << m - (2 * i) << endl; */
        /* cout << "i, j: " << i << ' ' << min((n - i) / 2, m - (2 * i)) <<
         * endl; */
        /* cout << endl; */

        int total = i + min((n - i) / 2, m - (2 * i));
        result = max(result, total);
    }

    cout << result << endl;
}
