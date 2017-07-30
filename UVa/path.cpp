/* brute force : iterative */

#include <algorithm>
#include <climits>
#include <cstring>
#include <iostream>
using namespace std;

int main()
{
    int m;
    string n;
    ios_base::sync_with_stdio(0);

    while (cin >> m) {
        int arr[m][m];

        for (int i = 0; i < m; i++) {
            cin >> n;

            for (int j = 0; j < m; j++) {
                arr[i][j] = n[j];
            }
        }

        int globaldist = INT_MIN;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                if (arr[i][j] == '1') {
                    int localdist = INT_MAX;

                    for (int k = 0; k < m; k++) {
                        for (int l = 0; l < m; l++) {
                            if (arr[k][l] == '3') {
                                if (abs(j - l) + abs(i - k) < localdist) {
                                    localdist = abs(j - l) + abs(i - k);
                                }
                            }
                        }
                    }

                    if (localdist > globaldist) {
                        globaldist = localdist;
                    }
                }
            }
        }

        cout << globaldist << '\n';
    }
}
