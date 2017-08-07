/* dp : 1d range sum */

#include <climits>
#include <iostream>
using namespace std;

int main()
{
    int b, s, tc = 0;

    cin >> b;

    while (b--) {
        cin >> s;

        int n[s];

        for (int i = 1; i < s; i++) {
            cin >> n[i];
        }

        int localMax = 0, globalMax = INT_MIN;
        int start = 1, maxStart, maxEnd;

        for (int i = 1; i < s; i++) {
            if (localMax < 0) {
                localMax = 0;
                start = i;
            }

            localMax += n[i];

            if (localMax > globalMax) {
                globalMax = localMax;

                maxStart = start;
                maxEnd = i + 1;
            } else if (localMax == globalMax) {
                if (i + 1 - start > maxEnd - maxStart) {
                    globalMax = localMax;

                    maxStart = start;
                    maxEnd = i + 1;
                }
            }
        }

        if (globalMax <= 0) {
            cout << "Route " << ++tc << " has no nice parts\n";
        } else {
            cout << "The nicest part of route " << ++tc << " is between stops "
                 << maxStart << " and " << maxEnd << '\n';
        }
    }
}
