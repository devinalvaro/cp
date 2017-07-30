#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

int main() {
    vector<int> a(4);
    cin >> a[1] >> a[2] >> a[3] >> a[4];

    string s;
    cin >> s;

    long long sum = 0;
    for (int i = 0; i < (int)s.length(); i++) {
        sum += a[s[i] - '0'];
    }

    cout << sum << endl;
}
