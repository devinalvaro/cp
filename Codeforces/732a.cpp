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
    int k, r;
    cin >> k >> r;

    int i;
    for (i = 1; i <= 9; i++) {
        if ((k * i) % 10 == r || (k * i) % 10 == 0) {
            break;
        }
    }

    cout << i << endl;
}
