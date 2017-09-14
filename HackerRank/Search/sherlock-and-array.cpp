#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<long long> sumLR(n), sumRL(n);
        for (int i = 0; i < n; i++) {
            sumLR[i] = a[i] + (i - 1 >= 0 ? sumLR[i - 1] : 0);
        }
        for (int i = n - 1; i >= 0; i--) {
            sumRL[i] = a[i] + (i + 1 < n ? sumRL[i + 1] : 0);
        }

        bool found = false;
        for (int i = 0; i < n && !found; i++) {
            if ((i - 1 >= 0 ? sumLR[i - 1] : 0) ==
                ((i + 1 < n ? sumRL[i + 1] : 0))) {
                found = true;
            }
        }

        if (found) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}
