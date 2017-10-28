#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> bits(10, 2);

    for (int i = 0; i < n; i++) {
        char c;
        int x;

        cin >> c >> x;

        for (int j = 0; j < 10; j++) {
            if (c == '|' && (x & (1 << j))) {
                bits[j] = 1;
            } else if (c == '&' && !(x & (1 << j))) {
                bits[j] = 0;
            } else if (c == '^' && (x & (1 << j))) {
                bits[j] ^= 1;
            }
        }
    }

    int a = 0, b = 0, c = 0;

    for (int j = 0; j < 10; j++) {
        if (bits[j] == 0) {
            b |= (1 << j);
        } else if (bits[j] == 1) {
            a |= (1 << j);
        } else if (bits[j] == 3) {
            c |= (1 << j);
        }
    }

    cout << 3 << '\n';
    cout << "| " << a << '\n';
    cout << "& " << (1023 ^ b) << '\n';
    cout << "^ " << c << '\n';

    return 0;
}
