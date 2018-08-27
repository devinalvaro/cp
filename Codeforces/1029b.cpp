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

    ve<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ve<bool> b(n);
    for (int i = 0; i < n - 1; i++) {
        b[i] = (a[i + 1] <= 2 * a[i]);
    }

    int result = 0, current = 0;
    for (int i = 0; i < n - 1; i++) {
        if (!b[i]) {
            current = 0;
            continue;
        }

        current++;
        result = max(result, current);
    }

    cout << result + 1 << endl;

    return 0;
}
