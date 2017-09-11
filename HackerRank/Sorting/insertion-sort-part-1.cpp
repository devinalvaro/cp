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

    int i = n - 2;
    int e = a[n - 1];
    while (i >= 0 && a[i] > e) {
        a[i + 1] = a[i];

        for (int i = 0; i < n; i++) {
            cout << a[i] << (i == n - 1 ? '\n' : ' ');
        }

        i--;
    }

    a[i + 1] = e;

    for (int i = 0; i < n; i++) {
        cout << a[i] << (i == n - 1 ? '\n' : ' ');
    }
}
