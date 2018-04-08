#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    vector<long long> a(n, 0);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }

    long long theorems = 0;
    vector<int> t(n, 0);
    for (int i = 0; i < n; i++) {
        scanf("%d", &t[i]);

        if (t[i]) {
            theorems += a[i];
        }
    }

    long long global_max = LLONG_MIN;
    long long local_max = 0;
    for (int i = 0; i < n; i++) {
        if (t[i] == 0) {
            local_max += a[i];
        }
        if (i >= k && t[i - k] == 0) {
            local_max -= a[i - k];
        }

        global_max = max(global_max, local_max);
    }

    theorems += global_max;
    printf("%lld\n", theorems);

    return 0;
}
