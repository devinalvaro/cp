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

    string s;
    cin >> s;

    ve<string> cans;

    for (char c = 'a'; c <= 'z'; c++) {
        int i;
        for (i = 0; i < n; i++) {
            if (s[i] == c) {
                break;
            }
        }

        if (i < n) {
            string t = s;
            t.erase(i, 1);

            cans.pb(t);
        }
    }

    sort(cans.begin(), cans.end());
    cout << cans[0] << endl;

    return 0;
}
