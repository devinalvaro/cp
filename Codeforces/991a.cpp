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
    int a, b, c, n;
    cin >> a >> b >> c >> n;

    int d = n - (a + b - c);
    if (d <= 0 || d + a > n || d + b > n) {
        d = -1;
    }
    cout << d << endl;

    return 0;
}
