#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    vector<long long> arr(n, 0);

    while (m--) {
        int a, b;
        long long k;
        cin >> a >> b >> k;
        a--;
        b--;

        arr[a] += k;
        if (b + 1 < n) {
            arr[b + 1] -= k;
        }
    }

    long long maxVal = LLONG_MIN, currentSum = 0;
    for (int i = 0; i < n; i++) {
        currentSum += arr[i];
        maxVal = max(maxVal, currentSum);
    }
    cout << maxVal << '\n';
}
