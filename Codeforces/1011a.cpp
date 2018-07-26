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
    int n, k;
    scanf("%d %d", &n, &k);

    string s;
    cin >> s;
    sort(s.begin(), s.end());

    int sum = (s[0] - 96);
    char pre = s[0];
    k--;

    for (int i = 1; i < n && k > 0; i++) {
        if (s[i] - pre <= 1) {
            continue;
        }

        sum += (s[i] - 96);
        pre = s[i];
        k--;
    }

    if (k > 0) {
        cout << -1 << endl;
    } else {
        cout << sum << endl;
    }

    return 0;
}
