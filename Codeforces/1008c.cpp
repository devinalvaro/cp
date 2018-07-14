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
    int most = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        m[a]++;
        most = max(most, m[a]);
    }

    cout << n - most << endl;

    return 0;
}
