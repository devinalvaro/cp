#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ll long long
#define ve vector
#define um unordered_map
#define us unordered_set

int main() {
    int n;
    cin >> n;

    string s;
    ve<int> bal(n, 0), low(n, INT_MAX);
    um<int, int> cnt;

    for (int i = 0; i < n; i++) {
        cin >> s;

        for (int j = 0; j < (int)s.size(); j++) {
            if (s[j] == '(') {
                bal[i]++;
            } else {
                bal[i]--;
            }

            low[i] = min(low[i], bal[i]);
        }

        if (bal[i] <= 0 && bal[i] == low[i]) {
            cnt[bal[i]]++;
        }
    }

    ll result = 0;
    for (int i = 0; i < n; i++) {
        if (low[i] < 0) {
            continue;
        }

        result += cnt[-bal[i]];
    }

    cout << result << endl;

    return 0;
}
