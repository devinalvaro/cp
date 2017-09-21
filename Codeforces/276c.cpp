#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);

    int n, q;
    cin >> n >> q;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<int> sum(n + 2, 0);
    while (q--) {
        int l, r;
        cin >> l >> r;

        sum[l]++;
        sum[r + 1]--;
    }

    vector<int> sums(n + 1);
    int currentSum = 0;
    for (int i = 1; i <= n; i++) {
        currentSum += sum[i];

        sums[i] = currentSum;
    }

    sort(a.begin() + 1, a.end());
    sort(sums.begin() + 1, sums.end());

    long long total = 0;
    for (int i = 1; i <= n; i++) {
        total += (long long)a[i] * (long long)sums[i];
    }

    cout << total << '\n';
}
