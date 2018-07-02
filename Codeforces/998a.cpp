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
    cin >> n;

    ve<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (n == 1 || (n == 2 && a[0] == a[1])) {
        cout << -1 << endl;
        return 0;
    }

    int idx = min_element(a.begin(), a.end()) - a.begin();
    printf("1\n%d\n", idx + 1);

    return 0;
}
