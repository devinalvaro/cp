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
    int n;
    cin >> n;

    set<pair<int, string>> best;
    ve<string> names = {"Kuro", "Shiro", "Katie"};
    for (int i = 0; i < 3; i++) {
        string s;
        cin >> s;

        map<char, int> m;
        for (char c : s) {
            m[c] += 1;
        }
        auto x = std::max_element(
            m.begin(), m.end(),
            [](const pair<int, int> &a, const pair<int, int> &b) {
                return a.second < b.second;
            });

        if (x->second == (int)s.size() && n == 1) {
            best.insert({min(x->second - 1, (int)s.size()), names[i]});
        } else {
            best.insert({min(x->second + n, (int)s.size()), names[i]});
        }
    }

    auto it = best.begin();
    it = next(it);
    if (it->first == next(it)->first) {
        cout << "Draw" << endl;
    } else {
        cout << next(it)->second << endl;
    }

    return 0;
}
