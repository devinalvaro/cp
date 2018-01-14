#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, pos, l, r;
    cin >> n >> pos >> l >> r;

    if (l == 1 && r == n) {
        cout << 0 << '\n';

        return 0;
    }

    int step = 0;

    if (abs(pos - l) < abs(pos - r)) {
        if (l > 1) {
            step += 1 + abs(pos - l);
            pos = l;
        } else {
            step += 1 + abs(pos - r);
            pos = r;
        }
    } else {
        if (r < n) {
            step += 1 + abs(pos - r);
            pos = r;
        } else {
            step += 1 + abs(pos - l);
            pos = l;
        }
    }

    if (r == l) {
        step -= 1;

        if (l > 1) {
            step += 1;
        }
        if (r < n) {
            step += 1;
        }
    }
    else if (pos == r && l > 1) {
        step += 1 + abs(r - l);
    } else if (pos == l && r < n) {
        step += 1 + abs(r - l);
    }

    cout << step << '\n';

    return 0;
}
