#include <bits/stdc++.h>

using namespace std;

#define fi  first
#define se  second
#define pb  push_back
#define ll  long long
#define ve  vector
#define pq  priority_queue
#define um  unordered_map
#define us  unordered_set
#define pii pair<int, int>
#define pll pair<ll, ll>

int main() {
    int n;
    scanf("%d", &n);

    string s;
    cin >> s;

    int i;
    for (i = 1; i < n; i++) {
        if (s[i] != s[i - 1]) {
            break;
        }
    }
    if (i == n) {
        printf("NO\n");
    } else {
        printf("YES\n");
        cout << s[i - 1] << s[i] << '\n';
    }

    return 0;
}
