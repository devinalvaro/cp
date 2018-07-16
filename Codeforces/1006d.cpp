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

int fl(int n) {
    if (n & 1) {
        return n / 2;
    }
    return (n - 1) / 2;
}

int main() {
    int n;
    string s, t;
    cin >> n >> s >> t;

    int cnt = 0;
    for (int i = 0; i <= fl(n); i++) {
        if (i == (n - i - 1)) {
            cnt += (s[i] == t[i] ? 0 : 1);
            continue;
        }

        char a = s[i], b = s[n - i - 1];
        char c = t[i], d = t[n - i - 1];

        if (c == d) {
            if (a != b) {
                cnt += 1;
            }
            continue;
        }

        um<char, int> s;
        s[c] += 1;
        s[d] += 1;

        if (s.find(a) == s.end()) {
            cnt += 1;
        } else {
            s[a] -= 1;
        }

        if (s.find(b) == s.end() || s[b] == 0) {
            cnt += 1;
        }
    }
    cout << cnt << endl;

    return 0;
}
