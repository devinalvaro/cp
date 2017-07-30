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

bool comp(long long a, long long b)
{
    return abs(10 - (a % 10)) < abs(10 - (b % 10));
}

int main()
{
    long long n, k;
    cin >> n >> k;

    vector<long long> a(n);
    for (long long i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end(), comp);

    for (long long i = 0; i < n; i++) {
        long long subtract = 10 - (a[i] % 10);

        if (k - subtract >= 0 && a[i] + subtract <= 100) {
            a[i] += subtract;
            k -= subtract;
        }
    }

    for (long long i = 0; i < n; i++) {
        long long subtract = min(100 - a[i], k);

        a[i] += subtract;
        k -= subtract;
    }

    long long sum = 0;
    for (long long i = 0; i < n; i++) {
        sum += a[i] / 10;
    }

    cout << sum << endl;
}
