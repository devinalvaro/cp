#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

string kb("qwertyuiop asdfghjkl; zxcvbnm,./");

int main()
{
    char d;
    string s;
    cin >> d >> s;

    for (int i = 0; i < (int)s.size(); i++) {
        string::iterator c = find(kb.begin(), kb.end(), s[i]);
        cout << *(c + (d == 'L' ? 1 : -1));
    }
    cout << endl;
}
