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
    int n, k;
    ll s;
    scanf("%d %d %lld", &n, &k, &s);

    if ((s + k - 1) / k > n - 1 || k > s) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";

    int pos = 1;

    while (k > 0) {
        int d = min(n - 1LL, s - (k - 1));

        if (pos + d <= n) {
            pos = pos + d;
        } else {
            pos = pos - d;
        }
        s -= d;

        k--;
        printf("%d ", pos);
    }
    printf("\n");

    return 0;
}
