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
    int n;
    scanf("%d", &n);

    map<int, int> m;

    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        m[a[i]] = i;
    }

    int deepest = -1;

    int b;
    for (int i = 0; i < n; i++) {
        scanf("%d", &b);

        int idx = m[b];
        if (idx > deepest) {
            printf("%d%c", idx - deepest, spnl(i, n));
        } else {
            printf("0%c", spnl(i, n));
        }
        deepest = max(deepest, idx);
    }

    return 0;
}
