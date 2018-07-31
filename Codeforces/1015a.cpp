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

    ve<bool> p(m);
    for (int i = 0; i < n; i++) {
        int l, r;
        scanf("%d %d", &l, &r);

        for (int i = l; i <= r; i++) {
            p[i - 1] = true;
        }
    }

    ve<int> ans;
    for (int i = 0; i < m; i++) {
        if (!p[i]) {
            ans.pb(i + 1);
        }
    }

    return 0;
}
