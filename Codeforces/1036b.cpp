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
    int q;
    cin >> q;

    while (q--) {
        ll n, m, k;
        cin >> n >> m >> k;

        if (k < max(n, m)) {
            printf("-1\n");
            continue;
        }

        if (n & 1 && m & 1) {
            if (k & 1) {
                printf("%lld\n", k);
            } else {
                printf("%lld\n", k - 2);
            }
            continue;
        }

        if (!(n & 1) && !(m & 1)) {
            if (k & 1) {
                printf("%lld\n", k - 2);
            } else {
                printf("%lld\n", k);
            }
            continue;
        }

        printf("%lld\n", k - 1);
    }

    return 0;
}
