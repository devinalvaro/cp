/* brute force : iterative */

#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;

    while (n--) {
        int a, b, c;
        cin >> a >> b >> c;
        int x, y, z;
        bool found = false;

        for (int i = -100; i <= 100; i++) {
            if (found) {
                break;
            }

            for (int j = -100; j <= 100; j++) {
                if (found) {
                    break;
                }

                for (int k = -100; k <= 100; k++) {
                    if (found) {
                        break;
                    } else if (i != k && i != j && j != k && i + j + k == a &&
                               i * j * k == b && i * i + j * j + k * k == c) {
                        found = true;
                        x = i;
                        y = j;
                        z = k;
                    }
                }
            }
        }

        if (!found) {
            cout << "No solution.\n";
        } else {
            cout << x << " " << y << " " << z << '\n';
        }
    }
}
