#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ll long long
#define ve vector
#define ii pair<int, int>
#define iv pair<int, ii>

int main() {
    ll n, a, b, c;
    cin >> n >> a >> b >> c;

    ll ans;
    if (n % 4 == 0) {
        ans = 0;
    } else if (n % 4 == 3) {
        ans = min(a, min(c + b, 3 * c));
    } else if (n % 4 == 2) {
        ans = min(2 * a, min(b, 2 * c));
    } else if (n % 4 == 1) {
        ans = min(3 * a, min(a + b, c));
    }

    cout << ans << endl;

    return 0;
}
