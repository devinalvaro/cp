#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> t(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }

    sort(t.begin(), t.end());

    long long sum = 0;
    for (vector<int>::iterator i = t.begin(); i != t.end(); i++) {
        if (sum <= *i) {
            sum += *i;
            continue;
        }

        vector<int>::iterator f = lower_bound(i + 1, t.end(), sum);
        if (f == t.end())
            continue;
        iter_swap(i, f);

        sum += *i;
    }

    sum = t[0];
    int satisfied = 1;
    for (int i = 1; i < n; i++) {
        if (sum <= t[i]) {
            satisfied++;
        }
        sum += t[i];
    }
    cout << satisfied << endl;
}
