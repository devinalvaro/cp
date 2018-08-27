#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back

#define ll long long
#define ms multiset
#define pq priority_queue
#define um unordered_map
#define us unordered_set
#define ve vector

#define pii pair<int, int>
#define pll pair<ll, ll>

int main() {
    int n;
    cin >> n;

    ve<int> l(n), r(n);
    ms<int> ls, rs;
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];

        ls.insert(l[i]);
        rs.insert(r[i]);
    }

    int best = 0;
    for (int i = 0; i < n; i++) {
        ls.erase(ls.find(l[i]));
        rs.erase(rs.find(r[i]));

        best = max(best, *rs.begin() - *ls.rbegin());

        ls.insert(l[i]);
        rs.insert(r[i]);
    }
    cout << best << endl;
}
