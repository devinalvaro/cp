#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);

    long long n, k;
    cin >> n >> k;

    cout << (k == 0 || k == n ? 0 : 1) << ' ';
    cout << min(2 * k, n - k) << '\n';
}
