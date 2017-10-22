#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }

    cout << 1 << ' ';

    int rightmost = n - 1;
    vector<bool> done(n);

    for (int i = 0; i < n; i++) {
        done[a[i]] = true;

        while (rightmost >= 0 && done[rightmost]) {
            rightmost--;
        }

        cout << 1 + ((i + 1) - (n - (rightmost + 1)));
        cout << (i == n - 1 ? '\n' : ' ');
    }
}
