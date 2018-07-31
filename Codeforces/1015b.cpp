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

int main() {
    int n;
    scanf("%d", &n);

    string s, t;
    cin >> s >> t;

    ve<int> ans;

    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == t[i]) {
            continue;
        }

        bool found = false;

        int j;
        for (j = i - 1; j >= 0; j--) {
            if (s[j] == t[i]) {
                found = true;
                break;
            }
        }

        if (!found) {
            cout << -1 << endl;
            return 0;
        }

        for (int k = j; k < i; k++) {
            s[k] = s[k + 1];
            ans.pb(k);
        }
        s[i] = t[i];
    }

    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] + 1 << (i == ans.size() - 1 ? '\n' : ' ');
    }

    return 0;
}
