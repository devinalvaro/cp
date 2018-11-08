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

#define ceil(x, y) ((x + y - 1) / y)
#define spnl(i, n) (i == n - 1 ? '\n' : ' ')
#define nend(i, c) (i == c.end() ? i : next(i))

int main() {
    int n;
    scanf("%d", &n);

    int v[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    int t[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &t[i]);
    }

    multiset<ll> ms;
    ll temp = 0;
    for (int i = 0; i < n; i++) {
        ms.insert(v[i] + temp);
        temp += t[i];

        auto lim = ms.lower_bound(temp + 1);

        ll sum = 0;
        for (auto it = ms.begin(); it != lim; it++) {
            sum += (*it - (temp - t[i]));
        }

        ms.erase(ms.begin(), lim);
        sum += t[i] * ms.size();

        printf("%lld%c", sum, spnl(i, n));
    }

    return 0;
}
