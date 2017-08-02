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
    int n;
    cin >> n;

    int best = 1, len = 1, last, current;
    cin >> current;
    for (int i = 1; i < n; i++) {
        last = current;
        cin >> current;

        if (current < last) {
            len = 1;
        } else {
            len++;
        }

        best = max(best, len);
    }

    cout << best << endl;
}