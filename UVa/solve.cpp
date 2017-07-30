/* dnc : bisection method */

#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

int p, q, r, s, t, u;

double eq(double x)
{
    return p * exp(-1 * x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x
        + u;
}

int main()
{
    while (cin >> p >> q >> r >> s >> t >> u) {
        double a = 0.0000, b = 1.0000, mid;

        if (eq(0) * eq(1) > 0) {
            cout << "No solution\n";
        } else {
            for (int i = 0; i < 30; i++) {
                mid = (a + b) / 2.0;

                if (eq(a) * eq(mid) <= 0) {
                    b = mid;
                } else {
                    a = mid;
                }
            }

            printf("%.4lf\n", mid);
        }
    }
}
