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

ll fac[20];
set<char> s;
set<string> ss;

ll countVariants(um<char, int> &dgts) {
    int len = 0;
    for (char c = '0'; c <= '9'; c++) {
        len += dgts[c];
    }

    ll cnt = fac[len];
    for (auto it = dgts.begin(); it != dgts.end(); it++) {
        char c = it->first;
        cnt /= fac[dgts[c]];
    }
    return cnt;
}

ll getVariants(string &m) {
    sort(m.begin(), m.end());
    if (ss.count(m)) {
        return 0;
    }
    ss.insert(m);

    um<char, int> dgts(10);
    for (char c : m) {
        dgts[c]++;
    }

    for (char c = '0'; c <= '9'; c++) {
        if (s.count(c) && dgts[c] == 0) {
            return 0;
        }
    }

    ll cnt = countVariants(dgts);
    if (dgts['0'] > 0) {
        dgts['0']--;
        cnt -= countVariants(dgts);
    }
    return cnt;
}

int main() {
    fac[0] = 1;
    for (int i = 1; i < 20; i++) {
        fac[i] = i * fac[i - 1];
    }

    string n;
    cin >> n;

    for (char c : n) {
        s.insert(c);
    }

    ll cnt = 0;

    int k = n.size();
    for (int i = 1; i <= (1 << k); i++) {
        string m;

        for (int j = 0; j < k; j++) {
            if (i & (1 << j)) {
                m += n[j];
            }
        }
        cnt += getVariants(m);
    }

    cout << cnt << endl;

    return 0;
}
