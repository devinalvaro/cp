#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ll long long
#define ve vector
#define um unordered_map
#define us unordered_set

int main() {
    int n, p;
    cin >> n >> p;

    string s;
    cin >> s;

    bool done = false;
    for (int i = 0; i < n - p && !done; i++) {
        if (s[i] == '.') {
            if (s[i + p] == '.') {
                s[i + p] = '1';
            }

            s[i] = (s[i + p] == '1') ? '0' : '1';
            done = true;
        } else {
            if (s[i + p] == '.') {
                s[i + p] = (s[i] == '1') ? '0' : '1';
                done = true;
            } else if (s[i] != s[i + p]) {
                done = true;
            }
        }
    }

    if (!done) {
        cout << "No\n";
        return 0;
    }

    for (int i = 0; i < n; i++) {
        if (s[i] == '.') {
            s[i] = '0';
        }
    }
    cout << s << endl;

    return 0;
}
