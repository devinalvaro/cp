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
    int n;
    cin >> n;

    map<int, int> s;

    vi a(n), x(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> x[i];
        s[a[i]] = x[i];
    }

    int m;
    cin >> m;

    vi b(m), y(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i] >> y[i];
    }

    ll sum = 0;
    for (int j = 0; j < m; j++) {
        if (s.find(b[j]) == s.end()) {
            sum += y[j];
            continue;
        }

        if (s[b[j]] < y[j]) {
            sum += y[j];
            s[b[j]] = 0;
        }
    }

    for (auto it = s.begin(); it != s.end(); it++) {
        sum += it->second;
    }

    cout << sum << endl;

    return 0;
}
