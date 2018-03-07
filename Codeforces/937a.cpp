#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    set<int> scores;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        if (a > 0) {
            scores.insert(a);
        }
    }

    cout << scores.size() << '\n';

    return 0;
}
