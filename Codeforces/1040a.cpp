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
    int n, a, b;
    cin >> n >> a >> b;

    ve<int> suits(n);
    for (int i = 0; i < n; i++) {
        cin >> suits[i];
    }

    int cost = 0;
    bool palindrome = true;
    for (int i = 0, j = n - 1; i <= j; i++, j--) {
        if (i == j && suits[i] == 2) {
            cost += min(a, b);
            continue;
        }

        if (suits[i] == 2 && suits[j] == 2) {
            cost += (2 * min(a, b));
            continue;
        }
        if (suits[i] == 2) {
            cost += (suits[j] == 0 ? a : b);
            continue;
        }
        if (suits[j] == 2) {
            cost += (suits[i] == 0 ? a : b);
            continue;
        }

        if (suits[i] != suits[j]) {
            palindrome = false;
            break;
        }
    }

    if (palindrome) {
        cout << cost << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
