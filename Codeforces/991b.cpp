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

bool isFive(int sum, int n) {
    return sum * 10 >= 45 * n;
}

int main() {
    int n;
    cin >> n;

    ve<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    sort(a.begin(), a.end());

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (isFive(sum, n)) {
            break;
        }

        sum += (5 - a[i]);
        cnt++;
    }

    cout << cnt << endl;

    return 0;
}
