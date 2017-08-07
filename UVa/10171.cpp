/* graph : apsp (standard) */

#include <climits>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, c, s, t;
    char a, b, x, y;

    while (cin >> n) {
        if (n == 0)
            break;

        vector<vector<int>> me(26, vector<int>(26, 10e6)),
            mig(26, vector<int>(26, 10e6));

        for (int i = 0; i < n; i++) {
            cin >> a >> b >> x >> y >> c;

            if (a == 'Y') {
                me[(int)x - 65][(int)y - 65] = c;

                if (b == 'B') {
                    me[(int)y - 65][(int)x - 65] = c;
                }
            } else {
                mig[(int)x - 65][(int)y - 65] = c;

                if (b == 'B') {
                    mig[(int)y - 65][(int)x - 65] = c;
                }
            }
        }

        for (int i = 0; i < 26; i++) {
            me[i][i] = 0;
            mig[i][i] = 0;
        }

        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    me[i][j] = min(me[i][j], me[i][k] + me[k][j]);
                    mig[i][j] = min(mig[i][j], mig[i][k] + mig[k][j]);
                }
            }
        }

        /* for (int i = 0; i < 26; i++) { */
        /*   for (int j = 0; j < 26; j++) { */
        /*     if (me[i][j] == 10e6) */
        /*       cout << ". "; */
        /*     else */
        /*       cout << me[i][j] << ' '; */
        /*   } */

        /*   cout << '\n'; */
        /* } */

        /* for (int i = 0; i < 26; i++) { */
        /*   for (int j = 0; j < 26; j++) { */
        /*     if (mig[i][j] == 10e6) */
        /*       cout << ". "; */
        /*     else */
        /*       cout << mig[i][j] << ' '; */
        /*   } */

        /*   cout << '\n'; */
        /* } */

        cin >> a >> b;

        s = (int)a - 65;
        t = (int)b - 65;

        int result = INT_MAX;

        for (int i = 0; i < 26; i++) {
            result = min(result, me[s][i] + mig[t][i]);
        }

        if (result >= 10e6) {
            cout << "You will never meet.\n";
        } else {
            cout << result;

            for (int i = 0; i < 26; i++) {
                if (me[s][i] + mig[t][i] == result) {
                    cout << ' ' << (char)(i + 65);
                }
            }

            cout << '\n';
        }
    }
}
