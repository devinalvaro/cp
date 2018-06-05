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

    vll x(n);
    set<ll> s;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        s.insert(x[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= 30; j++) {
            ll low = x[i] - (1LL << j);
            ll up = x[i] + (1LL << j);

            if (s.find(low) != s.end() && s.find(up) != s.end()) {
                cout << 3 << "\n";
                cout << low << " " << x[i] << " " << up << "\n";

                return 0;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= 30; j++) {
            ll up = x[i] + (1LL << j);

            if (s.find(up) != s.end()) {
                cout << 2 << "\n";
                cout << x[i] << " " << up << "\n";

                return 0;
            }
        }
    }

    cout << 1 << "\n";
    cout << x[0] << "\n";

    return 0;
}
