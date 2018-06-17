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
    int n, m;
    cin >> n >> m;

    ve<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    set<int> s;
    for (int i = 0; i < m; i++) {
        int b;
        cin >> b;
        s.insert(b);
    }

    ve<int> ans;
    for (int i = 0; i < n; i++) {
        if (s.find(a[i]) != s.end()) {
            ans.pb(a[i]);
        }
    }

    for (size_t i = 0; i < ans.size(); i++) {
        cout << ans[i] << (i == ans.size() - 1 ? '\n' : ' ');
    }

    return 0;
}
