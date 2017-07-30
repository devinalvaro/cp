#include <cmath>
#include <iostream>

using namespace std;

int main()
{
    long long n, a, b;
    cin >> n >> a >> b;

    if (6 * n <= a * b) {
        cout << a * b << endl;
        cout << a << ' ' << b << endl;

        return 0;
    }

    long long initSmall = a < b ? a : b;
    long long initLarge = a > b ? a : b;
    long long area = 1e18;
    long long bestSmall, bestLarge;

    for (long long p = initSmall; p * p < 6 * n; p++) {
        long long q = (6 * n) / p;
        if (p * q < 6 * n) {
            q++;
        }

        if (q < initLarge) {
            continue;
        }

        if (p * q < area) {
            area = p * q;
            bestSmall = p;
            bestLarge = q;
        }
    }

    cout << area << endl;
    cout << (initSmall == a ? bestSmall : bestLarge) << ' '
         << (initLarge == b ? bestLarge : bestSmall) << endl;
}
