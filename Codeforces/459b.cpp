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
    long long n;
    cin >> n;

    vector<long long> b(n);
    for (long long i = 0; i < n; i++) {
        cin >> b[i];
    }

    sort(b.begin(), b.end());

    long long min_value = b[0], max_value = b[n - 1];

    cout << max_value - min_value << ' ';

    if (min_value == max_value) {
        cout << n * (n - 1) / 2 << endl;
        return 0;
    }

    vector<long long>::iterator i = upper_bound(b.begin(), b.end(), min_value);
    vector<long long>::iterator j = lower_bound(b.begin(), b.end(), max_value);

    cout << (long long)(i - b.begin()) * (long long)(b.end() - j) << endl;
}
