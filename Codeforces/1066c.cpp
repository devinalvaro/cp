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
    int q;
    scanf("%d", &q);

    deque<pii> dq;
    map<int, int> pos;

    char c; int id;
    scanf(" %c %d", &c, &id);
    dq.push_front({id, 0});
    pos[id] = 0;

    while (--q) {
        char c; int id;
        scanf(" %c %d", &c, &id);

        if (c == 'L') {
            int p = dq.front().se;
            dq.push_front({id, p - 1});
            pos[id] = p - 1;
        } else if (c == 'R') {
            int p = dq.back().se;
            dq.push_back({id, p + 1});
            pos[id] = p + 1;
        } else {
            int l = dq.front().se, r = dq.back().se;
            int p = pos[id];
            printf("%d\n", min(abs(p - l), abs(p - r)));
        }
    }

    return 0;
}
