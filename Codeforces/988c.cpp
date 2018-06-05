#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

int main() {
    int k;
    cin >> k;

    map<int, vector<int>> a;
    vector<int> s(k);
    for (int i = 0; i < k; i++) {
        int n;
        cin >> n;

        a[i].assign(n, 0);

        int sum = 0;
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            sum += a[i][j];
        }
        s[i] = sum;
    }

    map<int, vii> b;
    map<int, set<int>> c;
    for (int i = 0; i < k; i++) {
        int m = a[i].size();

        for (int j = 0; j < m; j++) {
            int index = s[i] - a[i][j];
            if (c[index].find(i) != c[index].end()) {
                continue;
            } else {
                c[index].insert(i);
            }
            b[index].pb({i + 1, j + 1});
        }
    }

    for (auto it = b.begin(); it != b.end(); it++) {
        if ((it->second).size() >= 2) {
            cout << "YES\n";
            cout << it->second[0].first << " " << it->second[0].second << "\n";
            cout << it->second[1].first << " " << it->second[1].second << "\n";

            return 0;
        }
    }

    cout << "NO\n";

    return 0;
}
