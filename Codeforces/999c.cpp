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
    string alphabets = "abcdefghijklmnopqrstuvwxyz";

    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    for (int i = 0; i < 26 && k; i++) {
        for (int j = 0; j < n && k; j++) {
            if (s[j] == alphabets[i]) {
                s[j] = '.';
                k--;
            }
        }
    }

    string r;
    for (int i = 0; i < n; i++) {
        if (s[i] != '.') {
            r += s[i];
        }
    }
    cout << r << endl;

    return 0;
}
