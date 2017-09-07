#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);

    int g;
    cin >> g;

    while (g--) {
        int n, m;
        long long x;
        cin >> n >> m >> x;

        vector<long long> a(n), b(m);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int j = 0; j < m; j++) {
            cin >> b[j];
        }

        long long sum = 0;
        int i = 0, j = 0;

        while (i < n && sum + a[i] <= x) {
            sum += a[i++];
        }

        int num = i;

        while (j < m && i >= 0) {
            sum += b[j++];

            while (sum > x && i > 0) {
                sum -= a[--i];
            }

            if (sum <= x) {
                num = max(num, i + j);
            }
        }

        cout << num << '\n';
    }
}
