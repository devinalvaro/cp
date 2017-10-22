#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;

    int dist = 0;

    if (n > 1) {
        dist += min(a, b);
        dist += (n - 2) * min(a, min(b, c));
    }

    cout << dist << '\n';
}
