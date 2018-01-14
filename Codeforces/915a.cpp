#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.rbegin(), a.rend());

    for (int i = 0; i < n; i++) {
        if (a[i] <= k && k % a[i] == 0) {
            cout << k / a[i] << '\n';

            break;
        }
    }

    return 0;
}
