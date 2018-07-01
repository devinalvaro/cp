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
    string s[2];
    cin >> s[0] >> s[1];

    int cnt = 0;
    for (int i = 0; i < s[0].size(); i++) {
        if (s[0][i] != '0' || s[1][i] != '0') {
            continue;
        }

        if (i > 0) {
            if (s[0][i - 1] == '0' || s[1][i - 1] == '0') {
                s[0][i] = 'X', s[1][i] = 'X';
                cnt++;
                continue;
            }
        }
        if (i + 1 < s[0].size()) {
            if (s[0][i + 1] == '0') {
                s[0][i + 1] = 'X';
                cnt++;
            } else if (s[1][i + 1] == '0') {
                s[1][i + 1] = 'X';
                cnt++;
            }
        }
    }

    cout << cnt << endl;

    return 0;
}
