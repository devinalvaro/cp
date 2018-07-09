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

    ve<int> a(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    a[n] = INT_MIN;

    ve<int> steps;
    for (int i = 0; i < n; i++) {
        if (a[i] >= a[i + 1]) {
            steps.pb(a[i]);
        }
    }

    cout << steps.size() << endl;
    for (int i = 0; i < steps.size(); i++) {
        cout << steps[i] << (i == steps.size() - 1 ? '\n' : ' ');
    }

    return 0;
}
