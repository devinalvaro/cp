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
    cin >> n;

    while (n--) {
        string s;
        cin >> s;

        bool balanced = true;
        stack<char> parens;
        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] == '(' || s[i] == '[') {
                parens.push(s[i]);
            } else if (!parens.empty()
                && ((s[i] == ')' && parens.top() == '(')
                       || (s[i] == ']' && parens.top() == '['))) {
                parens.pop();

                continue;
            } else {
                balanced = false;

                break;
            }
        }

        if (balanced) {
            cout << "ya\n";
        } else {
            cout << "tidak\n";
        }
    }
}
