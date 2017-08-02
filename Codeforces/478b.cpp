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

long long binomial(long long n) { return n * (n - 1) / 2; }

int main()
{
    long long n, m;
    cin >> n >> m;

    long long mini;
    if (n % m == 0) {
        mini = m * binomial(n / m);
    } else {
        long long outlier = n - (m * (n / m));
        long long inlier = m - outlier;

        mini = outlier * binomial((n / m) + 1) + inlier * binomial(n / m);
    }

    long long maxi = binomial(n - m + 1);
    cout << mini << ' ' << maxi << endl;
}
