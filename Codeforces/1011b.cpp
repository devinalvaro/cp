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
    scanf("%d %d", &n, &m);

    ve<int> p(101);
    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        p[a] += 1;
    }
    sort(p.rbegin(), p.rend());

    int days = 1;
    while (true) {
        auto q = p;

        int k = n;
        for (int i = 0; i < 101 && k > 0;) {
            if (q[i] >= days) {
                q[i] -= days;
                k--;
            } else {
                i++;
            }
        }

        if (k > 0) {
            break;
        }
        days++;
    }
    cout << days - 1 << endl;

    return 0;
}
