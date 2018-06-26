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

    ve<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int i;
    for (i = 0; i < n; i++) {
        if (k < a[i]) {
            break;
        }
    }
    int j;
    for (j = n - 1; j >= i + 1; j--) {
        if (k < a[j]) {
            break;
        }
    }

    cout << i + (n - j - 1) << endl;

    return 0;
}
