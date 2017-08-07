/* brute force : iterative */

#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int t, d, q;
    long long p, range[10000][2];
    string car, brand[10000];
    cin >> t;

    while (t--) {
        cin >> d;

        for (int i = 0; i < d; i++) {
            cin >> brand[i] >> range[i][0] >> range[i][1];
        }

        cin >> q;

        while (q--) {
            cin >> p;
            car = "UVEWVEUVEWVE";

            for (int i = 0; i < d; i++) {
                if (range[i][0] <= p && p <= range[i][1]) {
                    if (car == "UVEWVEUVEWVE") {
                        car = brand[i];
                    } else {
                        car = "UVEWVEUVEWVE";
                        i = d;
                    }
                }
            }

            if (car == "UVEWVEUVEWVE") {
                car = "UNDETERMINED";
            }

            cout << car << '\n';
        }

        if (t != 0) {
            cout << '\n';
        }
    }
}
