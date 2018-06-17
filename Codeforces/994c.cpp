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

bool isInside(pii p, pii a[]) {
    return (p.first >= a[0].first) && (p.second >= a[0].second) &&
           (p.first <= a[3].first) && (p.second <= a[3].second);
}

int main() {
    pii a[4], b[4];
    for (int i = 0; i < 4; i++) {
        cin >> a[i].first >> a[i].second;
    }
    for (int i = 0; i < 4; i++) {
        cin >> b[i].first >> b[i].second;
    }

    sort(a, a + 4);
    sort(b, b + 4);

    for (int x = b[0].first; x <= b[3].first; x++) {
        int d = b[0].second -
                (x <= b[1].first ? (x - b[0].first) : (b[3].first - x));
        int u = (2 * b[0].second) - d;

        for (int y = d; y <= u; y++) {
            if (isInside({x, y}, a)) {
                cout << "YES\n";
                return 0;
            }
        }
    }

    cout << "NO\n";

    return 0;
}
