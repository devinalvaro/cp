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
    int n, t;
    cin >> n >> t;

    string s;
    vector<char> q;
    cin >> s;
    for (int i = 0; i < n; i++) {
        q.push_back(s[i]);
    }

    for (int x = 0; x < t; x++) {
        int i = 0;
        while (i < n - 1) {
            if (q[i] == 'B' && q[i + 1] == 'G') {
                q[i] = 'G';
                q[i + 1] = 'B';

                i++;
            }
            i++;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << q[i];
    }
    cout << endl;
}
