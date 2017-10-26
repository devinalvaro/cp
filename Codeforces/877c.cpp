#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    int odd = 0, even = 0;
    for (int i = 1; i <= n; i++) {
        if (i & 1) {
            odd++;
        } else {
            even++;
        }
    }

    cout << even + odd + even << '\n';

    for (int i = 2; i <= n; i += 2) {
        cout << i << ' ';
    }
    for (int i = 1; i <= n; i += 2) {
        cout << i << ' ';
    }
    for (int i = 2; i <= n; i += 2) {
        cout << i << (i == n || i == n - 1 ? '\n' : ' ');
    }

    return 0;
}
