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

    vector<int> sum(n, 1), dum(n, 1);
    for (int i = 1; i < n; i++) {
        if (s[i] != s[i - 1]) {
            sum[i] += sum[i - 1];
        }
    }
    for (int i = n - 2; i >= 0; i--) {
        if (s[i] != s[i + 1]) {
            dum[i] += dum[i + 1];
        }
    }

    int result = 1;
    for (int i = 0; i < n; i++) {
        result = max(result, sum[i]);
    }
    if (s[n - 1] != s[0]) {
        result = max(result, min(sum[n - 1] + dum[0], n));
    }

    cout << result << endl;

    return 0;
}
