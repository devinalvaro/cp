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
    ll x, y;
    cin >> n >> x >> y;

    string s;
    cin >> s;

    int cnt = (s[0] == '0');
    for (int i = 1; i < n; i++) {
        cnt += (s[i] == '0' && s[i - 1] == '1');
    }

    if (cnt == 0) {
        cout << 0 << endl;
        return 0;
    }

    ll cost = LLONG_MAX;
    for (int i = 0; i < cnt; i++) {
        cost = min(cost, (x * i) + (y * (cnt - i)));
    }

    cout << cost << endl;

    return 0;
}
