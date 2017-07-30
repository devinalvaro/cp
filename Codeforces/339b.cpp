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
    int n, m;
    cin >> n >> m;

    long long steps = 0, pos = 1, task;
    for (int i = 0; i < m; i++) {
        cin >> task;

        long long dist = task - pos;
        if (dist < 0) {
            dist += n;
        }

        steps += dist;
        pos = task;
    }

    cout << steps << endl;
}
