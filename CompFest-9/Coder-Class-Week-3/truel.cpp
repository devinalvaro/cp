#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int count_ones_from_integer(int value)
{
    int count;
    for (count = 0; value != 0; count++, value &= value - 1) {
        ;
    }
    return count;
}

int main()
{
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> out_degrees(n, 0);

        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;

            for (size_t j = 0; j < s.size(); j++) {
                char c = s[j];

                if (48 <= c && c <= 57) {
                    out_degrees[i] += count_ones_from_integer(c - 48);
                } else if (65 <= c && c <= 90) {
                    out_degrees[i] += count_ones_from_integer(c - 55);
                } else if (97 <= c && c <= 122) {
                    out_degrees[i] += count_ones_from_integer(c - 61);
                } else {
                    out_degrees[i] += count_ones_from_integer(c + 22);
                }
            }
        }

        sort(out_degrees.begin(), out_degrees.end());

        bool seru = false;

        for (int i = 0; i < n; i++) {
            if (out_degrees[i] != i) {
                seru = true;

                break;
            }
        }

        if (seru) {
            cout << "SERU PISAN\n";
        } else {
            cout << "MANA SERUNYA\n";
        }
    }
}
