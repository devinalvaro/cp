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

int main()
{
    string s;
    cin >> s;

    vector<int> n;
    for (int i = 0; i < (int)s.length(); i += 2) {
        n.push_back(s[i] - '0');
    }

    sort(n.begin(), n.end());

    for (int i = 0; i < (int)n.size() - 1; i++) {
        cout << n[i] << '+';
    }
    cout << n[(int)n.size() - 1] << endl;
}
