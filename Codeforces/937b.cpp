#include <bits/stdc++.h>

using namespace std;

bool has_grasshopper(int num, int p) {
    if (num <= p) {
        return true;
    }

    for (int i = 2; i <= p && i <= sqrt(num); i++) {
        if (num % i == 0) {
            return true;
        }
    }

    return false;
}

int main() {
    int p, y;
    cin >> p >> y;

    for (int i = y; i > p; i--) {
        if (!has_grasshopper(i, p)) {
            cout << i << '\n';

            return 0;
        }
    }

    cout << -1 << '\n';

    return 0;
}
