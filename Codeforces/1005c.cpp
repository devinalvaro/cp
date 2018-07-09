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
    cin >> n;

    ve<int> a(n);
    um<int, int> s;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s[a[i]]++;
    }

    ve<ve<ll>> comps(n, ve<ll>(32));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= 31; j++) {
            comps[i][j] = (1 << j) - a[i];
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        bool has = false;
        for (int j = 0; j <= 31; j++) {
            if (s.find(comps[i][j]) != s.end()) {
                if (a[i] != comps[i][j] || s[a[i]] > 1) {
                    has = true;
                    break;
                }
            }
        }

        if (!has) {
            cnt++;
        }
    }
    cout << cnt << endl;

    return 0;
}
