#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    if (n + 1 == n * (n + 1)) {
        cout << -1 << '\n';
    } else {
        cout << n << ' ' << n + 1 << ' ' << n * (n + 1) << '\n';
    }
}
