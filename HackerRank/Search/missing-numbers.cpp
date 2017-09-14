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

    int m;
    cin >> m;

    vector<int> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int i = 0, j = 0;
    while (j < m) {
        if (a[i] == b[j]) {
            i++;
            j++;

            continue;
        }

        cout << b[j] << ' ';

        while (b[j] != a[i]) {
            j++;
        }
    }
    cout << '\n';
}
