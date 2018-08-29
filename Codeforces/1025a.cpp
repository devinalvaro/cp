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
    int n;
    cin >> n;

    string s;
    cin >> s;

    map<char, int> cnt;
    for (char c : s) {
        cnt[c]++;
    }

    for (auto it = cnt.begin(); it != cnt.end(); it++) {
        if (it->second >= 2) {
            cout << "Yes\n";
            return 0;
        }
    }

    if (cnt.size() == 1) {
        cout << "Yes\n";
        return 0;
    }

    cout << "No\n";

    return 0;
}
