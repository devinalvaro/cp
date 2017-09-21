#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int m;
    cin >> m;

    vector<pair<long long, long long>> wh(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> wh[i].first >> wh[i].second;

        a[wh[i].first] =
            max(a[wh[i - 1].first] + wh[i - 1].second, a[wh[i].first]);

        cout << a[wh[i].first] << '\n';
    }
}
