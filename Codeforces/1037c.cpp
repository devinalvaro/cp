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

    string a, b;
    cin >> a >> b;

    int cost = 0;

    ve<bool> done(n);
    for (int i = 0; i + 1 < n; i++) {
        if (done[i] || a[i] == b[i])
            continue;

        if (a[i] == b[i + 1] && a[i + 1] == b[i]) {
            cost++;
            done[i] = true;
            done[i + 1] = true;
        }
    }
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i])
            continue;

        if (!done[i]) {
            cost++;
        }
    }

    printf("%d\n", cost);

    return 0;
}
