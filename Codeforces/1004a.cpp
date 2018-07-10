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
    ll d;
    cin >> n >> d;

    ve<ll> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    sort(x.begin(), x.end());

    ll cnt = 0;
    for (int i = 0; i < n - 1; i++) {
        if (x[i] + d == x[i + 1] - d) {
            cnt++;
        } else if (x[i] + d < x[i + 1] - d) {
            cnt += 2;
        }
    }
    cout << cnt + 2 << endl;

    return 0;
}
