#include <bits/stdc++.h>

using namespace std;

int main() {
    long long a, b;
    cin >> a >> b;

    if (b - a >= 10) {
        cout << 0 << '\n';
    } else {
        int result = 1;
        for (long long i = a + 1; i <= b; i++) {
            result *= (i % 10);
            result %= 10;
        }
        cout << result << '\n';
    }
}
