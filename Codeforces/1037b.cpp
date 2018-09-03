#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define ll long long
#define ve vector
#define pq priority_queue
#define um unordered_map
#define us unordered_set

#define pii pair<int, int>
#define pll pair<ll, ll>

int main() {
    int n, s;
    scanf("%d %d", &n, &s);

    ve<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    sort(a.begin(), a.end());

    if (a[n / 2] == s) {
        printf("0\n");
        return 0;
    }

    if (a[n / 2] > s) {
        ll sum = 0;
        for (int j = 0; j <= n / 2; j++) {
            if (a[j] > s) {
                sum += (a[j] - s);
            }
        }
        printf("%lld\n", sum);

        return 0;
    }

    if (a[n / 2] < s) {
        ll sum = 0;
        for (int j = n / 2; j < n; j++) {
            if (a[j] < s) {
                sum += (s - a[j]);
            }
        }
        printf("%lld\n", sum);

        return 0;
    }

    return 0;
}
