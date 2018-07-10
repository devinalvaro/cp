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
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    set<int> s;

    ve<int> dp(n);
    for (int i = n - 1; i >= 0; i--) {
        s.insert(a[i]);
        dp[i] = s.size();
    }

    s.clear();

    ll cnt = 0;
    for (int i = 0; i < n - 1; i++) {
        if (s.find(a[i]) != s.end()) {
            continue;
        }

        s.insert(a[i]);
        cnt += dp[i + 1];
    }
    cout << cnt << endl;

    return 0;
}
