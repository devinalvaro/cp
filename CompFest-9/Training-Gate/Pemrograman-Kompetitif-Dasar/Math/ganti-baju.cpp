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

    double q;
    cin >> q;

    q /= (double)100;
    double p = (double)1 - q;

    double total_chance = 0, chance = 1;
    for (int i = 0; i < 1000000; i++) {
        total_chance += chance;

        chance *= (p * p);
    }

    cout << fixed << setprecision(12) << total_chance * q << '\n';
}
