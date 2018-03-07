#include <bits/stdc++.h>

using namespace std;

int main() {
    long long a, b;
    cin >> a >> b;

    while (a != 0 && b != 0) {
        if (a >= 2 * b) {
            long long k = a / (2 * b);
            a -= k * (2 * b);
        } else if (b >= 2 * a) {
            long long k = b / (2 * a);
            b -= k * (2 * a);
        } else {
            break;
        }
    }

    cout << a << ' ' << b << '\n';

    return 0;
}
