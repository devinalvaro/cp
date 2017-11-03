#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;

    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == '0')
            continue;

        int zero_count = 0;
        for (int j = i + 1; j < (int)s.size(); j++) {
            if (s[j] == '0') {
                zero_count++;
            }

            if (zero_count >= 6) {
                cout << "yes\n";

                return 0;
            }
        }
    }

    cout << "no\n";

    return 0;
}
