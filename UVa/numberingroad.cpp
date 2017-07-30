/* math : simpler ones */

#include <cmath>
#include <iostream>
using namespace std;

int main()
{
    int n, r, t = 1;
    cin >> r >> n;

    while (n != 0 || r != 0) {
        cout << "Case " << t++ << ": ";

        if ((r - 1) / n > 26) {
            cout << "impossible\n";
        } else {
            cout << (r - 1) / n << '\n';
        }

        cin >> r >> n;
    }
}
