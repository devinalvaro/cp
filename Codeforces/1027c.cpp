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

double f(int p, int q) {
    return (4.0 * (p + q) * (p + q)) / (1LL * p * q);
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);

        um<int, int> m;
        for (int i = 0; i < n; i++) {
            int a;
            scanf("%d", &a);
            m[a] += 1;
        }

        ve<int> a;
        for (auto it = m.begin(); it != m.end(); it++) {
            if (it->se >= 2) {
                a.pb(it->fi);

                if (it->se >= 4) {
                    a.pb(it->fi);
                }
            }
        }
        sort(a.begin(), a.end());

        int res = a[0], des = a[1];
        double best = DBL_MAX;

        for (int i = 0; i + 1 < a.size(); i++) {
            if (f(a[i], a[i + 1]) < best) {
                best = f(a[i], a[i + 1]);
                res = a[i], des = a[i + 1];
            }
        }

        printf("%d %d %d %d\n", res, res, des, des);
    }

    return 0;
}
