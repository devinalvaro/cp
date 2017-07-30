#include <cstring>
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    long long a[n], sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    if (sum % 3 != 0) {
        cout << 0 << endl;
        return 0;
    }

    long long cnt[n], cntSum[n], cntVal = 0;
    memset(cnt, 0, sizeof(cnt));

    for (int i = n - 1; i >= 0; i--) {
        cntVal += a[i];
        if (cntVal == (sum / 3)) {
            cnt[i] = 1;
        }
    }

    cntSum[n - 1] = cnt[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        cntSum[i] = cnt[i] + cntSum[i + 1];
    }

    long long tempSum = 0, result = 0;
    for (int i = 0; i < n - 2; i++) {
        tempSum += a[i];
        if (tempSum == (sum / 3)) {
            result += cntSum[i + 2];
        }
    }

    cout << result << endl;
}
