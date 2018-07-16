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

    int a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a & 1) {
            cout << a;
        } else {
            cout << a - 1;
        }
        cout << (i == n - 1 ? '\n' : ' ');
    }

    return 0;
}
