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

#define ceil(x, y) (x + y - 1) / y
#define spnl(i, n) " \n"[(i == n - 1)]

int n, x, y;
string s;

bool can(int len) {
    map<char, int> cnt;

    for (int i = 0; i < len; i++) {
        cnt[s[i]]++;
    }

    int x0 = 0, y0 = 0;
    for (int i = len; i < n; i++) {
        if (s[i] == 'U')
            y0++;
        if (s[i] == 'D')
            y0--;
        if (s[i] == 'L')
            x0--;
        if (s[i] == 'R')
            x0++;
    }

    int d = abs(x - x0) + abs(y - y0);
    if (d <= len) {
        return true;
    }

    for (int i = 0; i + len < n; i++) {
        if (s[i] == 'U')
            y0++;
        if (s[i] == 'D')
            y0--;
        if (s[i] == 'L')
            x0--;
        if (s[i] == 'R')
            x0++;

        if (s[i + len] == 'U')
            y0--;
        if (s[i + len] == 'D')
            y0++;
        if (s[i + len] == 'L')
            x0++;
        if (s[i + len] == 'R')
            x0--;

        int d = abs(x - x0) + abs(y - y0);
        if (d <= len) {
            return true;
        }
    }

    return false;
}

int main() {
    scanf("%d", &n);
    cin >> s;
    scanf("%d %d", &x, &y);

    int d = abs(x) + abs(y);
    if (d > n || d % 2 != n % 2) {
        printf("-1\n");
        return 0;
    }

    int lo = 0, hi = n, res = -1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;

        if (can(mid)) {
            res = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    printf("%d\n", res);

    return 0;
}
