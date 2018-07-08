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

    map<int, int> m;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        m[a] += 1;
    }

    int res = 0;
    for (auto it = m.begin(); it != m.end(); it++) {
        res = max(res, it->second);
    }
    cout << res << endl;

    return 0;
}
