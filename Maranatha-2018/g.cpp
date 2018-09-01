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
    cin >> t;

    int tc = 0;

    while (t--) {
        int n;
        cin >> n;

        int gold[n + 1];
        memset(gold, 0, sizeof(gold));

        for (int i = 1; i <= n; i++) {
            cin >> gold[i];

            int yield = 0;
            for (int j = 2; j <= 4; j++) {
                if (i - j >= 2 && i - j <= n) {
                    yield = max(yield, gold[i - j]);
                }
            }
            gold[i] += yield;
        }

        // for (int i = 1; i <= n; i++) {
        //     cout << gold[i] << ' ';
        // }
        // cout << '\n';

        printf("Case %d :%d\n", ++tc, gold[n]);
    }

    return 0;
}
