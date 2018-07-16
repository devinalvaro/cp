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

    ll sum = 0;
    um<ll, int> idx;

    for (int i = 0; i < n; i++) {
        cin >> a[i];

        sum += a[i];
        if (idx.find(sum) == idx.end()) {
            idx[sum] = i;
        }
    }

    sum = 0;
    ll best = 0;

    for (int i = n - 1; i >= 0; i--) {
        sum += a[i];
        if (idx.find(sum) != idx.end() && idx[sum] < i) {
            best = sum;
        }
    }

    cout << best << endl;

    return 0;
}
