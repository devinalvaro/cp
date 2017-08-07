/* brute force : iterative */

#include <iostream>
using namespace std;

int main()
{
    int k, s[20];
    cin >> k;

    while (k != 0) {
        for (int i = 0; i < k; i++) {
            cin >> s[i];
        }

        for (int i = 0; i < k - 5; i++) {
            for (int j = i + 1; j < k - 4; j++) {
                for (int a = j + 1; a < k - 3; a++) {
                    for (int b = a + 1; b < k - 2; b++) {
                        for (int p = b + 1; p < k - 1; p++) {
                            for (int q = p + 1; q < k; q++) {
                                cout << s[i] << ' ' << s[j] << ' ' << s[a]
                                     << ' ' << s[b] << ' ' << s[p] << ' '
                                     << s[q] << '\n';
                            }
                        }
                    }
                }
            }
        }

        cin >> k;

        if (k != 0) {
            cout << '\n';
        }
    }
}
