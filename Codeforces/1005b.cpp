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
    string s, t;
    cin >> s >> t;

    int i = s.size() - 1, j = t.size() - 1;
    while (i >= 0 && j >= 0) {
        if (s[i] != t[j]) {
            break;
        }
        i--, j--;
    }

    cout << i + j + 2 << endl;

    return 0;
}
