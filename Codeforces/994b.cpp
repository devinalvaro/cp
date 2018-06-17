#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ll long long
#define ve vector
#define um unordered_map
#define us unordered_set

int main() {
    int n, k;
    cin >> n >> k;

    um<int, pair<int, int>> id;
    ve<pair<int, int>> pc(n);
    for (int i = 0; i < n; i++) {
        cin >> pc[i].first;
        id[i].first = pc[i].first;
    }
    for (int i = 0; i < n; i++) {
        cin >> pc[i].second;
        id[i].second = pc[i].second;
    }

    sort(pc.begin(), pc.end());

    long long s = 0;
    ve<ll> c(n);
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++) {
        s += pc[i].second;
        pq.push(pc[i].second);

        if (pq.size() > (size_t)k) {
            s -= pq.top();
            pq.pop();
        }

        c[i] = s;
    }

    ve<int> p(n);
    for (int i = 0; i < n; i++) {
        p[i] = pc[i].first;
    }

    for (int i = 0; i < n; i++) {
        auto it = lower_bound(p.begin(), p.end(), id[i].first);

        int j = it - p.begin();
        ll coins = id[i].second + (j >= 1 ? c[j - 1] : 0);

        cout << coins << (i == n - 1 ? '\n' : ' ');
    }
}
