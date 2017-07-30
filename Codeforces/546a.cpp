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

int main() {
    int k, n, w;
    cin >> k >> n >> w;

    for (int i = 1; i <= w; i++) {
        n -= i * k;
    }

    cout << (n >= 0 ? 0 : abs(n)) << endl;
}
