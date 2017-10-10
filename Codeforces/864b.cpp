#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    int result = 0;
    set<int> letters;
    for (int i = 0; i < n; i++) {
        if (s[i] != tolower(s[i])) {
            result = max(result, (int)letters.size());
            letters.clear();
        } else {
            letters.insert(s[i]);
        }
    }
    result = max(result, (int)letters.size());

    cout << result << '\n';
}
