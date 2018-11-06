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
#define spnl(i, n) " \n"[(i == 0)]

const int N = 1e5;

int n;
int a[N], b[N];

bool dfs(int i, int current, stack<int> &s) {
    if (i == n - 1) {
        s.push(current);
        return true;
    }
    if (i - 1 >= 0) {
        if ((s.top() | current) != a[i - 1]) {
            return false;
        }
        if ((s.top() & current) != b[i - 1]) {
            return false;
        }
    }

    s.push(current);

    if (a[i] == 0 && b[i] == 0) {
        if (s.top() == 0 && dfs(i + 1, 0, s)) return true;
    }

    if (a[i] == 1 && b[i] == 0) {
        if (s.top() == 0 && dfs(i + 1, 1, s)) return true;
        if (s.top() == 1 && dfs(i + 1, 0, s)) return true;
    }
    if (a[i] == 1 && b[i] == 1) {
        if (s.top() == 1 && dfs(i + 1, 1, s)) return true;
    }

    if (a[i] == 2 && b[i] == 0) {
        if (s.top() == 0 && dfs(i + 1, 2, s)) return true;
        if (s.top() == 2 && dfs(i + 1, 0, s)) return true;
    }
    if (a[i] == 2 && b[i] == 2) {
        if (s.top() == 2 && dfs(i + 1, 2, s)) return true;
    }

    if (a[i] == 3 && b[i] == 0) {
        if (s.top() == 0 && dfs(i + 1, 3, s)) return true;
        if (s.top() == 1 && dfs(i + 1, 2, s)) return true;
        if (s.top() == 2 && dfs(i + 1, 1, s)) return true;
        if (s.top() == 3 && dfs(i + 1, 0, s)) return true;
    }
    if (a[i] == 3 && b[i] == 1) {
        if (s.top() == 1 && dfs(i + 1, 3, s)) return true;
        if (s.top() == 3 && dfs(i + 1, 1, s)) return true;
    }
    if (a[i] == 3 && b[i] == 2) {
        if (s.top() == 2 && dfs(i + 1, 3, s)) return true;
        if (s.top() == 3 && dfs(i + 1, 2, s)) return true;
    }
    if (a[i] == 3 && b[i] == 3) {
        if (s.top() == 3 && dfs(i + 1, 3, s)) return true;
    }

    s.pop();
    return false;
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n - 1; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n - 1; i++) {
        scanf("%d", &b[i]);
    }

    for (int i = 0; i < 4; i++) {
        stack<int> s;
        if (dfs(0, i, s)) {
            printf("YES\n");

            ve<int> ans;
            while (!s.empty()) {
                ans.pb(s.top());
                s.pop();
            }
            for (int i = ans.size() - 1; i >= 0; i--) {
                printf("%d%c", ans[i], spnl(i, ans.size()));
            }

            return 0;
        }
    }

    printf("NO\n");

    return 0;
}
