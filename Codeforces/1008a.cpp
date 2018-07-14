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

bool isVowel(char c) {
    return c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o';
}

int main() {
    string s;
    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        if (!isVowel(s[i]) && s[i] != 'n') {
            if (i == s.size() - 1 || !isVowel(s[i + 1])) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }

    cout << "YES" << endl;

    return 0;
}
