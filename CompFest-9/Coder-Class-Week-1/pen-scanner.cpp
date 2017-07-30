#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);

    string s;
    vector<vector<int>> scan(7);
    for (int i = 0; i < 9; i++) {
        cin >> s;

        if (i == 0 || i == 8)
            continue;

        for (int j = 0; j < (int)s.size(); j++) {
            if (j % 5 == 0)
                continue;

            scan[i - 1].push_back(s[j] - '0');
        }
    }

    /* for (int i = 0; i < 7; i++) { */
    /*     for (int j = 0; j < (int)scan[i].size(); j++) { */
    /*         cout << scan[i][j]; */
    /*     } */
    /*     cout << '\n'; */
    /* } */

    map<string, char> letter;
    letter["0000011001100000011001100110"] = 'A';
    letter["0000011001100000011001100000"] = 'B';
    letter["0000011101110111011101110000"] = 'C';
    letter["1111111111111111111111111111"] = ' ';

    for (int j = 0; j < (int)scan[0].size(); j += 4) {
        string s;

        for (int i = 0; i < 7; i++) {
            for (int k = 0; k < 4; k++) {
                if (scan[i][j + k] == 0)
                    s += '0';
                else
                    s += '1';
            }
        }

        if (s == "0000011001100000011001100110")
            cout << 'A';
        if (s == "0000011001100000011001100000")
            cout << 'B';
        if (s == "0000011101110111011101110000")
            cout << 'C';
        if (s == "1111111111111111111111111111")
            cout << ' ';
    }
    cout << '\n';
}
