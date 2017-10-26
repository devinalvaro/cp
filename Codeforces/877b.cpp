#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.size();

    vector<int> a_count(n + 1, 0), b_count(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        a_count[i] = (s[i - 1] == 'a' ? 1 : 0) + a_count[i - 1];
        b_count[i] = (s[i - 1] == 'b' ? 1 : 0) + b_count[i - 1];
    }

    int max_length = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            max_length =
                max(max_length, (a_count[i]) + (b_count[j] - b_count[i]) +
                                    (a_count[n] - a_count[j]));
        }
    }

    cout << max_length << '\n';

    return 0;
}
