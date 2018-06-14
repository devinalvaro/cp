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
    string s;
    cin >> s;

    for (size_t i = 1; i < s.size() - 1; i++) {
        set<int> f;
        f.insert(s[i - 1]);
        f.insert(s[i]);
        f.insert(s[i + 1]);
        f.erase('.');

        if (f.size() == 3) {
            cout << "Yes\n";
            return 0;
        }
    }

    cout << "No\n";

    return 0;
}
