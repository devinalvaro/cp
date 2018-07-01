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

bool check(ll n, ll k) {
    ll cur = n, sum = 0;
    while (cur > 0) {
        sum += min(cur, k);
        cur -= min(cur, k);
        cur -= (cur / 10);
    }
    return sum * 2 >= n;
}

int main() {
    ll n;
    cin >> n;

    ll l = 1, r = n;
    while (l < r) {
        ll mid = (l + r) >> 1;

        if (check(n, mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    cout << l << endl;

    return 0;
}
