#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> squares(n, 0);
    for (int i = 0; i < m; i++) {
        int c;
        cin >> c;

        squares[c - 1]++;
    }

    int result = INT_MAX;
    for (int i = 0; i < n; i++) {
        result = min(result, squares[i]);
    }
    cout << result << '\n';

    return 0;
}
