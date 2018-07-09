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
    string s;
    cin >> s;

    int n = s.size();

    ve<ll> zum(n + 1);
    for (int i = 0; i < n; i++) {
        zum[i + 1] = (s[i] - '0') + zum[i];
    }

    int cnt = 0;

    int left = 0;
    for (int j = 1; j <= n; j++) {
        for (int i = j - 1; i >= left; i--) {
            if ((zum[j] - zum[i]) % 3 == 0) {
                cnt++;
                left = j;
                break;
            }
        }
    }

    cout << cnt << endl;

    return 0;
}
