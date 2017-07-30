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

int main()
{
    char s[100005], *p;
    cin >> s;

    if ((p = strstr(s, "AB")) and strstr(p + 2, "BA"))
        cout << "YES" << endl;
    else if ((p = strstr(s, "BA")) and strstr(p + 2, "AB"))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
