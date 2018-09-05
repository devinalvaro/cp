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
    int n, m;
    scanf("%d %d", &n, &m);

    string s, t;
    cin >> s >> t;

    int wildcard = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '*') {
            wildcard = i;
            break;
        }
    }

    if (wildcard == -1) {
        if (s == t) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
        return 0;
    }

    bool possible = true;

    for (int i = 0, j = 0; i < wildcard; i++, j++) {
        if (j >= m || s[i] != t[j]) {
            possible = false;
        }
    }
    for (int i = n - 1, j = m - 1; i > wildcard; i--, j--) {
        if (j < wildcard || s[i] != t[j]) {
            possible = false;
        }
    }

    if (possible) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
