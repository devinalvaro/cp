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
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        bool palindrome = true;
        for (int i = 0, j = n - 1; i < j; i++, j--) {
            if (s[i] != s[j] && s[i] + 1 != s[j] - 1 && s[i] - 1 != s[j] + 1) {
                palindrome = false;
                break;
            }
        }

        if (palindrome) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
