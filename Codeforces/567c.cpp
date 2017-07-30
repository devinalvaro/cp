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

    int n, k;
    cin >> n >> k;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    map<long long, vector<long long>> num_pos;
    for (int i = 0; i < n; i++) {
        num_pos[a[i]].push_back(i);
    }

    long long ways = 0;
    for (int i = 1; i < n - 1; i++) {
        if (a[i] % k != 0)
            continue;

        long long prev_num = a[i] / k;
        long long next_num = a[i] * k;

        if (num_pos.find(prev_num) == num_pos.end()
            || num_pos.find(next_num) == num_pos.end())
            continue;

        long long prev_num_sum
            = lower_bound(num_pos[prev_num].begin(), num_pos[prev_num].end(), i)
            - num_pos[prev_num].begin();
        long long next_num_sum
            = num_pos[next_num].end() - upper_bound(num_pos[next_num].begin(),
                                            num_pos[next_num].end(), i);

        ways += prev_num_sum * next_num_sum;
    }

    cout << ways << endl;
}
