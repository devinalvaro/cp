/* math : mathematical simulation */

#include <iostream>
using namespace std;

int main()
{
    long long n, k;

    while (cin >> n >> k) {
        long long i = 0;

        while (i < n) {
            int b = (n - i) / k;
            i = n;

            if (b != 0) {
                i -= n % k;
            }

            n += b;
        }

        cout << i << '\n';
    }
}
