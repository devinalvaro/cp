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

    ve<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    ve<int> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }

    int j = 0;
    for (int i = 0; i < n && j < m; i++) {
        if (c[i] > a[j]) {
            continue;
        }

        j++;
    }
    cout << j << endl;

    return 0;
}
