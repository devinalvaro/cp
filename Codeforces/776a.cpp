#include <bits/stdc++.h>

using namespace std;

int main() {
    string name1, name2;
    cin >> name1 >> name2;

    int n;
    cin >> n;
    while (n--) {
        cout << name1 << ' ' << name2 << '\n';

        string killed, replacement;
        cin >> killed >> replacement;

        if (name1 == killed) {
            name1 = replacement;
        } else {
            name2 = replacement;
        }
    }
    cout << name1 << ' ' << name2 << '\n';
}
