#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    int x = INT_MIN;

    for (int i = 1; i <= n - 1; i++) {
        if (a < i || b < (n - i))
            continue;

        x = max(x, min(a / i, b / (n - i)));
    }

    cout << x << '\n';

    return 0;
}
