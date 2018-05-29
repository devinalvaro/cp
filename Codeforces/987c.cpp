#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int main() {
    int n;
    scanf("%d\n", &n);

    vi s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    vi c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    vii r(n, {INT_MAX, INT_MAX});
    for (int i = 1; i < n - 1; i++) {
        for (int j = 0; j < i; j++) {
            if (s[j] < s[i]) {
                r[i].fi = min(r[i].fi, c[j]);
            }
        }

        for (int j = i + 1; j < n; j++) {
            if (s[i] < s[j]) {
                r[i].se = min(r[i].se, c[j]);
            }
        }
    }

    int result = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (r[i].fi == INT_MAX || r[i].se == INT_MAX) {
            continue;
        }

        result = min(result, r[i].fi + c[i] + r[i].se);
    }

    if (result == INT_MAX) {
        result = -1;
    }
    printf("%d\n", result);

    return 0;
}
