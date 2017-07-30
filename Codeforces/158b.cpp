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
    int n;
    cin >> n;

    int s;
    vector<int> g(5);
    for (int i = 0; i < n; i++) {
        cin >> s;
        g[s]++;
    }

    int total = 0;

    total += g[4];

    total += g[3];
    g[1] -= min(g[3], g[1]);

    total += g[2] / 2;
    g[2] %= 2;
    total += g[2];
    g[1] -= min(g[1], g[2] * 2);

    total += g[1] / 4 + (g[1] % 4 == 0 ? 0 : 1);

    cout << total << endl;
}
