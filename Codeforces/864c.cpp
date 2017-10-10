#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, f, k;
    cin >> a >> b >> f >> k;

    int fuel = b;
    int refuelTimes = 0;
    int type = 0;
    long long dist;

    while (k) {
        if (type == 0 || type == 3) { // start to f
            dist = f;
        } else { // f to end
            dist = a - f;
        }

        if (type == 0 || type == 2) { // from start or end
            if (fuel < dist) {
                cout << -1 << '\n';

                return 0;
            }
        } else { // from gas station
            if (k > 1) {
                dist <<= 1;
            }

            if (b < dist) {
                cout << -1 << '\n';

                return 0;
            }

            if (fuel < dist) {
                fuel = b;
                refuelTimes++;
            }

            if (k > 1) {
                dist >>= 1;
            }
        }

        fuel -= dist;
        type = (type + 1) % 4;

        if (type == 0 || type == 2) { // reach start or end
            k--;
        }
    }

    cout << refuelTimes << '\n';
}
