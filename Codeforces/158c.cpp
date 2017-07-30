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
    int n;
    cin >> n;

    string pwd = "/";

    while (n--) {
        string c, s;

        cin >> c;
        if (c == "pwd") {
            cout << pwd << endl;

            continue;
        }

        cin >> s;
        if (s[0] == '/') {
            pwd = s + '/';
        } else {
            pwd += s + '/';
        }

        while (pwd.find("..") != string::npos) {
            int found = (int)pwd.find("..");
            int start = found - 2, end = found + 2;

            while (pwd[start - 1] != '/') {
                start--;
            }

            pwd.erase(start, end - start + 1);
        }
    }
}
