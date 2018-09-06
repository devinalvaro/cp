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
    int n;
    scanf("%d", &n);

    int a[n], b[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }

    sort(a, a + n);
    sort(b, b + n);

    int turn = 0, i = n - 1, j = n - 1;
    ll sa = 0, sb = 0;
    while (i >= 0 || j >= 0) {
        if (turn == 0) {
            if (i < 0 || (i >= 0 && j >= 0 && b[j] > a[i])) {
                j--;
            } else if (j < 0 || (i >= 0 && j >= 0 && b[j] <= a[i])) {
                sa += a[i];
                i--;
            }
        } else if (turn == 1) {
            if (j < 0 || (i >= 0 && j >= 0 && a[i] > b[j])) {
                i--;
            } else if (i < 0 || (i >= 0 && j >= 0 && a[i] <= b[j])) {
                sb += b[j];
                j--;
            }
        }
        turn ^= 1;
    }
    printf("%lld\n", sa - sb);

    return 0;
}
