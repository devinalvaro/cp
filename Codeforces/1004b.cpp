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
    int n, m;
    scanf("%d %d", &n, &m);

    ve<pii> x(n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x[i].fi, &x[i].se);
    }

    int c = 1;
    for (int i = 0; i < n; i++) {
        c ^= 1;
        printf("%d", c);
    }
    printf("\n");

    return 0;
}
