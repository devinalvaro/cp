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
    cin >> n >> m;

    ve<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int k = n / m;
    ve<ve<int>> mods(m);

    for (int i = 0; i < n; i++) {
        mods[a[i] % m].push_back(i);
    }

    ll sum = 0;
    stack<int> oop;

    for (int i = 0; i < 2 * m; i++) {
        int j = i % m;

        while (mods[j].size() > k) {
            oop.push(mods[j].back());
            mods[j].pop_back();
        }

        while (mods[j].size() < k && !oop.empty()) {
            int t = oop.top();

            mods[j].push_back(t);
            oop.pop();

            int d = (j - (a[t] % m) + m) % m;
            sum += d;
            a[t] += d;
        }
    }

    cout << sum << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << (i == n - 1 ? '\n' : ' ');
    }

    return 0;
}
