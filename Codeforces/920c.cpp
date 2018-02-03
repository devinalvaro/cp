#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    string s;
    cin >> s;

    int lb = INT_MAX;
    int ub = INT_MIN;

    int left = 0;

    bool sortable = true;

    for (int i = 0; i < n; i++) {
        lb = min(lb, a[i]);
        ub = max(ub, a[i]);

        if (i < n - 1 && s[i] == '0') {
            if (lb != left + 1 || ub != i + 1) {
                sortable = false;

                break;
            }

            lb = INT_MAX;
            ub = INT_MIN;

            left = i + 1;
        }
    }

    if (sortable) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}
