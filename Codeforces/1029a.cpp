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

// https://cp-algorithms.com/string/prefix-function.html
int prefix_function(string s) {
    int n = s.length();

    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }

    return pi[n - 1];
}

int main() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    string t = s.substr(0, n - prefix_function(s));

    while (--k) {
        cout << t;
    }
    cout << s << endl;

    return 0;
}
