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

int main() {
    int n;
    cin >> n;

    int p[n];
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    double total = 0;
    for (int i = 0; i < n; i++) {
        total += (double)p[i];
    }

    cout << fixed << setprecision(12) << total / ((double)n) << endl;
}
