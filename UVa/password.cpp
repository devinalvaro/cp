/* brute force : recursive backtracking */

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> v(5);
vector<string> r;

void backtrack(int i, string s)
{
    if (i == 5) {
        r.push_back(s);
    } else {
        for (vector<char>::iterator it = v[i].begin(); it != v[i].end(); it++) {
            backtrack(i + 1, s + *it);
        }
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--) {
        int k;
        string s[12];

        for (int i = 0; i < 5; i++) {
            v[i].clear();
        }

        r.clear();
        cin >> k;

        for (int i = 0; i < 12; i++) {
            cin >> s[i];
        }

        for (int j = 0; j < 5; j++) {
            for (int i = 0; i < 6; i++) {
                bool duo = false;

                for (int k = 6; k < 12; k++)
                    if (s[i][j] == s[k][j]) {
                        duo = true;
                    }

                for (vector<char>::iterator it = v[j].begin(); it != v[j].end();
                     it++)
                    if (*it == s[i][j]) {
                        duo = false;
                    }

                if (duo) {
                    v[j].push_back(s[i][j]);
                }
            }
        }

        for (int i = 0; i < 5; i++) {
            sort(v[i].begin(), v[i].end());
        }

        backtrack(0, "");

        if ((unsigned long)k > r.size()) {
            cout << "NO\n";
        } else {
            cout << r[k - 1] << '\n';
        }
    }
}
