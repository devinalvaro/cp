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

    queue<string> q;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if (x == 1) {
            string s;
            cin >> s;

            q.push(s);
        } else if (x == 2) {
            cout << q.front() << '\n';

            q.pop();
        }
    }
}
