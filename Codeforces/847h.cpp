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

    vector<int> incArr(n), decArr(n);
    for (int i = 0; i < n; i++) {
        incArr[i] = a[i];

        if (i > 0 && incArr[i] <= incArr[i - 1]) {
            incArr[i] = incArr[i - 1] + 1;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        decArr[i] = a[i];

        if (i < n - 1 && decArr[i] <= decArr[i + 1]) {
            decArr[i] = decArr[i + 1] + 1;
        }
    }

    vector<long long> incDiffSum(n), decDiffSum(n);
    for (int i = 0; i < n; i++) {
        incDiffSum[i] =
            (i > 0 ? incDiffSum[i - 1] : 0) + (long long)(incArr[i] - a[i]);
    }
    for (int i = n - 1; i >= 0; i--) {
        decDiffSum[i] =
            (i < n - 1 ? decDiffSum[i + 1] : 0) + (long long)(decArr[i] - a[i]);
    }

    long long minRequests = decDiffSum[0];
    for (int i = 0; i < n; i++) {
        if (i + 1 < n && incArr[i] == decArr[i + 1])
            continue;

        minRequests = min(minRequests,
                          incDiffSum[i] + (i + 1 < n ? decDiffSum[i + 1] : 0));
    }
    cout << minRequests << '\n';
}
