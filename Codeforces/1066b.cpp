#include <bits/stdc++.h>

using namespace std;

#define fi  first
#define se  second
#define pb  push_back
#define ll  long long
#define ve  vector
#define pq  priority_queue
#define um  unordered_map
#define us  unordered_set
#define pii pair<int, int>
#define pll pair<ll, ll>

#define ceil(x, y) (x + y - 1) / y
#define spnl(i, n) " \n"[(i == n - 1)]

int main() {
    int n, r;
    scanf("%d %d", &n, &r);

    set<int> heaters;
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        if (a) {
            heaters.insert(i);
        }
    }

    ve<int> cnt(n);
    for (auto it = heaters.begin(); it != heaters.end(); it++) {
        for (int i = -r + 1; i < r; i++) {
            if (*it + i < 0 || *it + i >= n)
                continue;

            cnt[*it + i] += 1;
        }
    }

    for (int i = 0; i < n; i++) {
        if (cnt[i] == 0) {
            puts("-1");
            return 0;
        }
    }

    map<int, bool> imp;
    for (auto it = heaters.begin(); it != heaters.end(); it++) {
        bool important = false;
        for (int i = -r + 1; i < r; i++) {
            if (*it + i < 0 || *it + i >= n)
                continue;

            if (cnt[*it + i] == 1) {
                important = true;
                break;
            }
        }

        if (important) {
            imp[*it] = true;
        } else {
            for (int i = -r + 1; i < r; i++) {
                if (*it + i >= 0 && *it + i < n)
                    cnt[*it + i]--;
            }
        }
    }

    int ans = 0;
    for (auto it = imp.begin(); it != imp.end(); it++) {
        if (it->second) {
            ans++;
        }
    }
    printf("%d\n", ans);

    return 0;
}
