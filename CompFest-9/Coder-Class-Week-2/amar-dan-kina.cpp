#include <algorithm>
#include <bitset>
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

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> num(n);
        map<int, int> num_count;
        vector<int> segment_count(n, 0);

        for (int i = 0; i < k; i++) {
            cin >> num[i];
            if (num_count.find(num[i]) == num_count.end()) {
                num_count[num[i]] = 1;
            } else {
                num_count[num[i]]++;
            }

            if (num_count[num[i]] == num[i]) {
                segment_count[k - 1]++;
            }
            if (num_count[num[i]] == num[i] + 1) {
                segment_count[k - 1]--;
            }
        }

        for (int i = k; i < n; i++) {
            segment_count[i] = segment_count[i - 1];

            num_count[num[i - k]]--;

            cin >> num[i];
            if (num_count.find(num[i]) == num_count.end()) {
                num_count[num[i]] = 1;
            } else {
                num_count[num[i]]++;
            }

            if (num[i - k] == num[i]) {
                continue;
            }

            if (num_count[num[i - k]] == num[i - k] - 1) {
                segment_count[i]--;
            }
            if (num_count[num[i]] == num[i] + 1) {
                segment_count[i]--;
            }
            if (num_count[num[i - k]] == num[i - k]) {
                segment_count[i]++;
            }
            if (num_count[num[i]] == num[i]) {
                segment_count[i]++;
            }
        }

        cout << accumulate(segment_count.begin() + k - 1, segment_count.end(),
                           0)
             << '\n';
    }
}
