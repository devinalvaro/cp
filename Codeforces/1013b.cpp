#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define ll long long
#define ve vector
#define pq priority_queue
#define um unordered_map
#define us unordered_set

#define pii pair<int, int>
#define pll pair<ll, ll>

bool inSet(us<int> &s, int n) {
    return s.find(n) != s.end();
}

int main() {
    int n, x;
    cin >> n >> x;

    ve<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    um<int, us<int>> nums, ands;
    for (int i = 0; i < n; i++) {
        nums[a[i]].insert(i);
        ands[a[i] & x].insert(i);
    }

    int best = INT_MAX;
    for (int i = 0; i < n; i++) {
        int p = a[i], q = a[i] & x;

        if (!inSet(nums[p], i) && nums[p].size() > 0)
            best = min(best, 0);
        if (inSet(nums[p], i) && nums[p].size() > 1)
            best = min(best, 0);

        if (!inSet(nums[q], i) && nums[q].size() > 0)
            best = min(best, 1);
        if (inSet(nums[q], i) && nums[q].size() > 1)
            best = min(best, 1);

        if (!inSet(ands[p], i) && ands[p].size() > 0)
            best = min(best, 1);
        if (inSet(ands[p], i) && ands[p].size() > 1)
            best = min(best, 1);

        if (!inSet(ands[q], i) && ands[q].size() > 0)
            best = min(best, 2);
        if (inSet(ands[q], i) && ands[q].size() > 1)
            best = min(best, 2);
    }

    if (best != INT_MAX) {
        cout << best << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
