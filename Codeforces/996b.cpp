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

    int best, mini = INT_MAX;
    for (int i = 0; i < n; i++) {
         int q = a[i] / n, r = a[i] % n;
         if (r > i) {
             q++;
         }

         if (q < mini) {
             mini = q;
             best = i + 1;
         }
    }
    cout << best << endl;

    return 0;
}
