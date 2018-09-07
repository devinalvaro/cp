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

    ve<ll> a(n + 1);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);

        a[i + 1] = a[i] + x;
    }

    int m;
    scanf("%d", &m);

    ve<ll> b(m + 1);
    for (int i = 0; i < m; i++) {
        int x;
        scanf("%d", &x);

        b[i + 1] = b[i] + x;
    }

    int cnt = 0;
    int last_i = 0, last_j = 0;
    int i = 1, j = 1;

    while (i <= n && j <= m) {
        ll current_a = a[i] - a[last_i];
        ll current_b = b[j] - b[last_j];

        // cout << i << ' ' << j << ' ' << current_a << ' ' << current_b << endl;

        if (current_a == current_b) {
            cnt++;
            last_i = i, last_j = j;
            i++, j++;
            continue;
        }

        if (current_a < current_b) {
            i++;
            continue;
        }
        if (current_b < current_a) {
            j++;
            continue;
        }
    }

    if (i <= n || j <= m) {
        cout << -1 << endl;
    } else {
        cout << cnt << endl;
    }

    return 0;
}
