#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int main()
{
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    double result = DBL_MIN;
    int a, b;
    for (int i = 1; i < n; i++) {
        int j = n - i;

        if (i >= j)
            break;

        if (gcd(i, j) == 1) {
            double fraction = (double)i / (double)j;

            if (fraction > result) {
                result = fraction;

                a = i;
                b = j;
            }
        }
    }
    cout << a << ' ' << b << '\n';
}
