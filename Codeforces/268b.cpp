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

    long long press = n, dist = 1;
    for (int i = n - 1; i >= 1; i--) {
        press += (long long)i * dist;
        dist++;
    }

    cout << press << endl;
}
