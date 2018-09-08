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
    int t;
    scanf("%d", &t);

    while (t--) {
        int l, n;
        scanf("%d %d", &l, &n);

        ve<int> a(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        sort(a.begin(), a.end());

        int days = max(a[0] - 1, 2 * (l - a[n - 1]));
        for (int i = 0; i < n - 1; i++) {
            days = max(days, (int)ceil((a[i + 1] - a[i] - 1) / 1.5));
        }
        printf("%d\n", days);
    }

    return 0;
}
