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

    int n;
    string s;
    cin >> n >> s;

    set<char> letters;
    for (int i = 0; i < n; i++) {
        letters.insert(s[i]);
    }

    map<char, vector<int>> last;
    for (set<char>::iterator c = letters.begin(); c != letters.end(); c++) {
        last[*c] = vector<int>(n);

        int current_last = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == *c) {
                current_last = i;
            }

            last[*c][i] = current_last;
        }
    }

    vector<int> len(n, 0);
    for (int i = 0; i < n; i++) {
        for (set<char>::iterator c = letters.begin(); c != letters.end(); c++) {
            if (last[*c][i] == -1) {
                len[i] = INT_MAX;

                break;
            }

            len[i] = max(len[i], i - last[*c][i] + 1);
        }
    }

    int answer = INT_MAX;
    for (int i = 0; i < n; i++) {
        answer = min(answer, len[i]);
    }

    cout << answer << endl;
}
