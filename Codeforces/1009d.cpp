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
    int n, m;
    cin >> n >> m;

    if (m < n - 1) {
        cout << "Impossible\n";
        return 0;
    }

    set<pii> edges;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (__gcd(i, j) == 1) {
                edges.insert({i, j});
            }

            if (edges.size() == m) {
                break;
            }
        }

        if (edges.size() == m) {
            break;
        }
    }

    if (edges.size() < m) {
        cout << "Impossible\n";
        return 0;
    }

    cout << "Possible\n";
    for (auto it = edges.begin(); it != edges.end(); it++) {
        cout << it->first << ' ' << it->second << '\n';
    }

    return 0;
}
