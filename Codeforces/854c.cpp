#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);

    int n, k;
    cin >> n >> k;

    vector<int> c(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }

    priority_queue<pair<int, int>> pq;

    for (int t = 1; t <= k; t++) {
        pq.push(make_pair(c[t], t));
    }

    vector<int> a(n + 1);
    long long total = 0;

    for (int t = 1 + k; t <= n + k; t++) {
        if (t <= n) {
            pq.push(make_pair(c[t], t));
        }

        a[pq.top().second] = t;
        total += (long long)pq.top().first * (long long)(t - pq.top().second);

        pq.pop();
    }

    cout << total << '\n';
    for (int t = 1; t <= n; t++) {
        cout << a[t] << (t == n ? '\n' : ' ');
    }
}
