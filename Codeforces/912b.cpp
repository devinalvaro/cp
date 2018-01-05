#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;

    long long m = 0;
    for (int i = 0; i < 64; i++) {
        if ((1LL << i) > n) {
            break;
        }

        m = i;
    }

    long long result = 1LL << m;

    if (k > 1) {
        result ^= (result - 1);
    }

    if (n > result) {
        result = n;
    }

    cout << result << '\n';

    return 0;
}
