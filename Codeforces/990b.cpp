#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ll long long
#define ve vector
#define um unordered_map
#define us unordered_set

int main() {
    int n, k;
    cin >> n >> k;

    ve<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int result = n;
    for (int i = 0; i < n; i++) {
        auto it = upper_bound(a.begin(), a.end(), a[i] + k);
        if (*prev(it) > a[i] && *prev(it) <= a[i] + k) {
            result--;
        }
    }

    cout << result << endl;

    return 0;
}
