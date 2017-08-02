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
    int n, p, q, total = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p >> q;

        if (q - p >= 2) {
            total++;
        }
    }

    cout << total << endl;
}
