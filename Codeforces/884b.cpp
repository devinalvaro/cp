#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (accumulate(a.begin(), a.end(), 0) == x - (n - 1)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}
