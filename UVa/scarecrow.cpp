/* greedy : classical */

#include <iostream>
#include <math.h>
using namespace std;

string s;

int main()
{
    int t, n;
    cin >> t;

    for (int j = 1; j <= t; j++) {
        cin >> n >> s;
        int scarecrow = 0;

        if (n == 1 && s[0] == '.') {
            scarecrow = 1;
        } else if (n > 1) {
            for (int i = 1; i < n; i++) {
                if (s[i - 1] == '.') {
                    scarecrow++;
                    s[i - 1] = '-';
                    s[i] = '-';

                    if (i != n - 1) {
                        s[i + 1] = '-';
                    }
                } else if (i == n - 1 && s[i] == '.') {
                    scarecrow++;
                    s[i - 1] = '-';
                    s[i] = '-';
                }
            }
        }

        cout << "Case " << j << ": " << scarecrow << '\n';
    }
}
