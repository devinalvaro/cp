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
    int n, k;
    cin >> n >> k;

    int i = 1;
    ve<int> pts;
    while (i <= n) {
        pts.pb(i);
        i += (2 * k) + 1;
    }

    int offset = k;
    if (pts.back() + offset > n) {
        int diff = pts.back() + offset - n;
        offset -= diff;
    }

    cout << pts.size() << endl;
    for (int i = 0; i < pts.size(); i++) {
        cout << pts[i] + offset << ' ';
    }
    cout << endl;

    return 0;
}
