#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int diff = INT_MAX;
    for (int i = 0; i < n - 1; i++) {
        diff = min(diff, a[i + 1] - a[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        if (a[i + 1] - a[i] == diff) {
            cout << a[i] << ' ' << a[i + 1] << ' ';
        }
    }
    cout << '\n';
}
