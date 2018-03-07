#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;

    int k = 0;
    for (int i = 0; k < 26 && i < (int)s.length(); i++) {
        char a = k + 97;

        if (s[i] <= a) {
            k++;
            s[i] = a;
        }
    }

    if (k == 26) {
        cout << s << '\n';
    } else {
        cout << -1 << '\n';
    }

    return 0;
}
