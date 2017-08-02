/* greedy : non classical */

#include <climits>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t, c = 0, n, d;
    string s;
    vector<vector<int>> v(110, vector<int>(2));
    cin >> t;

    while (t--) {
        c++;
        cin >> n >> d;

        for (int i = 1; i <= n; i++) {
            cin >> s;

            if (s[0] == 'B') {
                v[i][0] = 0;
            } else {
                v[i][0] = 1;
            }

            v[i][1] = atoi(s.substr(2, s.length() - 2).c_str());
        }

        v[0][0] = 0;
        v[0][1] = 0;
        v[n + 1][0] = 0;
        v[n + 1][1] = d;
        int leap_from = 0, max_step = INT_MIN, i = 1;

        while (i <= n + 1) {
            if (v[i][0] == 0) { // is big stone
                if (v[i][1] - v[leap_from][1] > max_step) {
                    max_step = v[i][1] - v[leap_from][1];
                }

                leap_from = i;
                i++;
            } else if (v[i][0] == 1) {  // is small stone
                if (v[i - 1][0] == 1) { // prev is small stone
                    if (v[i][1] - v[leap_from][1] > max_step) {
                        max_step = v[i][1] - v[leap_from][1];
                    }

                    v[i][0] = -1; // now drowned
                    leap_from = i;
                    i++;
                } else { // prev is big stone
                    i++;
                }
            } else { // is drowned stone
                i++;
            }
        }

        leap_from = n + 1;
        i = n;

        while (i >= 0) {
            if (v[i][0] != -1) { // isn't drowned stone
                if (abs(v[i][1] - v[leap_from][1]) > max_step) {
                    max_step = abs(v[i][1] - v[leap_from][1]);
                }

                leap_from = i;
                i--;
            } else { // is drowned stone
                i--;
            }
        }

        cout << "Case " << c << ": " << max_step << '\n';
    }
}
