#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);

    int n;
    long long k;
    cin >> n >> k;

    long long l = 1LL, r = pow(2, n + 1) - 1LL;
    while (l <= r) {
        long long m = (l + r) / 2LL;

        if (m == k) {
            break;
        } else if (m < k) {
            l = m + 1;
        } else if (m > k) {
            r = m - 1;
        }

        n--;
    }

    cout << ++n << '\n';
}
