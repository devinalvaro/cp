#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n, m, k;
    scanf("%lld %lld %lld", &n, &m, &k);

    if (k < n) {
        printf("%lld 1\n", k + 1);

        return 0;
    }

    k -= n;
    m -= 1;

    long long t = k / m;

    printf("%lld ", n - t);

    if (t & 1) {
        printf("%lld\n", 1 + m - (k % m));
    } else {
        printf("%lld\n", 2 + (k % m));
    }

    return 0;
}
