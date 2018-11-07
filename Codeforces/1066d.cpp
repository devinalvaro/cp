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

const int N = 2e5;

int n, m, k;
int a[N], b[N];

bool can(int start) {
    for (int i = 0; i < m; i++) {
        b[i] = k;
    }

    int i, j;
    for (i = start, j = 0; i < n && j < m;) {
        if (a[i] <= b[j]) {
            b[j] -= a[i];
            i++;
        } else {
            j++;
        }
    }

    if (i == n) {
        return true;
    }
    return false;
}

int main() {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int l = 0, r = n - 1, ans = 0;
    while (l <= r) {
        int m = (l + r) / 2;

        if (can(m)) {
            ans = n - m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    printf("%d\n", ans);

    return 0;
}
