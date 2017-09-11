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

    for (int j = 1; j < n; j++) {
        int e = a[j];

        int i = j - 1;
        while (i >= 0 && a[i] > e) {
            a[i + 1] = a[i];

            i--;
        }

        a[i + 1] = e;

        for (int i = 0; i < n; i++) {
            cout << a[i] << (i == n - 1 ? '\n' : ' ');
        }
    }
}
