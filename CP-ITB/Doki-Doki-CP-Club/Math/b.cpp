/* Counting Solutions to an Integral Equation */

#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n;
    while (scanf("%lld", &n) != EOF) {
        n /= 2;

        printf("%lld\n", (long long)((n + 2) * (double(n + 1) / 2)));
    }

    return 0;
}
