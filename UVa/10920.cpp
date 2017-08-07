/* ds : 2d array */

#include <cmath>
#include <iostream>
using namespace std;

int main()
{
    long long sz, p;

    while (true) {
        cin >> sz >> p;

        if (sz == 0 && p == 0) {
            break;
        }

        long long root = sqrt(p);

        if (root * root != p && root % 2 == 1) {
            root += 2;
        } else if (root % 2 == 0) {
            root += 1;
        }

        long long i = root / 2, j = root / 2;

        if (root * root != 1) {
            long long group = ((root * root) - p) / (root - 1);

            if (group == 0) {
                i -= (root * root) - p;
            } else if (group == 1) {
                i *= -1;
                j -= ((root * root) - p) - (root - 1);
            } else if (group == 2) {
                j *= -1;
                i -= (root - 1) - (((root * root) - p) - (root - 1) * 2);
            } else {
                j -= (root - 1) - (((root * root) - p) - (root - 1) * 3);
            }
        }

        cout << "Line = " << ((sz / 2) + 1) + i << ", ";
        cout << "column = " << ((sz / 2) + 1) + j << ".\n";
    }
}
