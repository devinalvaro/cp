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
    ll n, k;
    scanf("%lld %lld", &n, &k);

    ll result = 0;
    if (k <= n) {
        result = (k / 2) - (k & 1 ? 0 : 1);
    } else {
        result = max(0LL, (n - (k - n) + 1) / 2);
    }
    printf("%lld\n", result);

    return 0;
}
