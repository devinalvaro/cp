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

    int n;
    cin >> n;

    vector<int> t(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }

    int best_sum = accumulate(t.begin(), t.end(), 0);
    for (int i = 2; i < n / 2; i++) {
        if (n % i != 0 || n / i < 3) {
            continue;
        }

        for (int j = 0; j < i; j++) {
            int sum = 0;

            for (int k = j; k < n; k += i) {
                sum += t[k];
            }

            best_sum = max(best_sum, sum);
        }
    }

    cout << best_sum << '\n';
}
