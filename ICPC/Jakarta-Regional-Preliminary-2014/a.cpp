#include <bits/stdc++.h>

using namespace std;

int main() {
    int tc;
    cin >> tc;

    for (int tn = 1; tn <= tc; tn++) {
        cout << "Case #" << tn << ": ";

        int n;
        cin >> n;

        int total = 0;
        for (int i = 0; i < n; i++) {
            int size;
            cin >> size;

            total += size;
        }

        if (total <= 16000) {
            cout << "16GB\n";
        } else if (total <= 32000) {
            cout << "32GB\n";
        } else if (total <= 64000) {
            cout << "64GB\n";
        } else {
            cout << "128GB\n";
        }
    }
}
