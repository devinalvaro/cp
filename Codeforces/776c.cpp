#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];

        a[i] += (i >= 1 ? a[i - 1] : 0);
    }

    long long result = 0;
    for (long long p = 1; p <= (long long)1e14; p *= k) {
        map<long long, int> numberCount;
        for (int i = 0; i < n; i++) {
            numberCount[a[i]]++;
        }

        result += numberCount[p];
        for (int l = 1; l < n; l++) {
            // a[r] - a[l - 1] == p
            result += numberCount[a[l - 1] + p];

            numberCount[a[l - 1]]--;
        }

        if (k == 1)
            break;
        if (k == -1 && p == -1)
            break;
    }
    cout << result << '\n';
}
