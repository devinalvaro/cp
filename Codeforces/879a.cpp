#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> s(n), d(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i] >> d[i];
    }

    int day = 0;
    for (int i = 0; i < n; i++) {
        while (day > s[i]) {
            s[i] += d[i];
        }
        day = s[i] + 1;
    }

    cout << day - 1 << '\n';

    return 0;
}
