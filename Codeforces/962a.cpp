#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    long long sum = 0;
    long long a[n];
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        sum += a[i];
    }

    long long temp = 0;
    for (int i = 0; i < n; i++) {
        temp += a[i];

        if (2 * temp >= sum) {
            printf("%d\n", i + 1);
            break;
        }
    }

    return 0;
}
