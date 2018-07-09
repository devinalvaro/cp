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
    int n, q;
    cin >> n >> q;

    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        cnt[a]++;
    }

    while (q--) {
        int x;
        cin >> x;

        int needs = 0;
        for (auto it = cnt.rbegin(); it != cnt.rend() && x > 0; it++) {
            if (it->first > x) {
                continue;
            }

            int need = min(it->second, x / it->first);
            x -= need * (it->first);

            needs += need;
        }

        if (x > 0) {
            cout << -1 << endl;
        } else {
            cout << needs << endl;
        }
    }

    return 0;
}
