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
    int n, result = 0;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) {
            result++;
        }
    }
    cout << result << endl;
}
