/* brute force : recursive backtracking */

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int t, n, num[12];
bool NONE;
string s1;
vector<string> R;

void backtrack(int x, int c, bool used[])
{
    if (x == t) {
        string s2("");
        bool FIRST = true;
        NONE = false;

        for (int i = 0; i < n; i++) {
            if (used[i] && FIRST) {
                FIRST = false;
                s2 += to_string(num[i]);
            } else if (used[i] && !FIRST) {
                s2 += "+" + to_string(num[i]);
            }
        }

        if (find(R.begin(), R.end(), s2) == R.end()) {
            R.push_back(s2);
        }
    } else if (c < n) {
        bool used1[12], used2[12];
        memset(used1, 0, sizeof used1);
        memset(used2, 0, sizeof used2);

        for (int i = 0; i < n; i++) {
            if (used[i]) {
                used1[i] = true;
                used2[i] = true;
            }
        }

        used1[c] = true;
        used2[c] = false;
        backtrack(x + num[c], c + 1, used1);
        backtrack(x, c + 1, used2);
    }
}

int main()
{
    cin >> t >> n;

    while (n != 0) {
        bool used[12];
        memset(used, 0, sizeof used);

        for (int i = 0; i < n; i++) {
            cin >> num[i];
        }

        cout << "Sums of " << t << ":\n";
        s1 = "";
        NONE = true;
        R.clear();
        backtrack(0, 0, used);

        if (NONE) {
            cout << "NONE\n";
        }

        vector<string>::iterator it;

        for (it = R.begin(); it < R.end(); it++) {
            cout << *it << '\n';
        }

        cin >> t >> n;
    }
}
