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

    int cnt = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1') {
            cnt++;
        }
    }

    s.erase(remove(s.begin(), s.end(), '1'), s.end());

    bool done = false;
    for (int i = 0; i < s.size(); i++) {
        if (!done && s[i] == '2') {
            while (cnt--) {
                cout << '1';
            }
            done = true;
        }

        cout << s[i];
    }
    while (cnt-- && !done) {
        cout << '1';
    }
    cout << endl;

    return 0;
}
