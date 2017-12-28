#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> k(3);
    cin >> k[0] >> k[1] >> k[2];

    int ones = 0, twos = 0, threes = 0, fours = 0;

    for (int i = 0; i < 3; i++) {
        if (k[i] == 1) {
            ones += 1;
        }
        if (k[i] == 2) {
            twos += 1;
        }
        if (k[i] == 3) {
            threes += 1;
        }
        if (k[i] == 4) {
            fours += 1;
        }
    }

    if (ones >= 1 || twos >= 2 || threes == 3 || (twos == 1 && fours == 2)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}
