#include <bits/stdc++.h>

using namespace std;

int main() {
    int tc;
    cin >> tc;

    cin >> ws;

    for (int tn = 1; tn <= tc; tn++) {
        cout << "Case #" << tn << ": ";

        string s;
        getline(cin, s);

        vector<string> hashtags;

        int i = 0, n = s.size();
        while (i < n) {
            if (s[i] != '#') {
                i++;

                continue;
            }

            string hashtag;

            int j = i + 1;
            while (j < n && ((j == i + 1 && isalpha(s[j])) ||
                                         (j > i + 1 && isalnum(s[j])))) {
                hashtag += s[j];

                j++;
            }

            if (!hashtag.empty()) {
                hashtags.push_back(hashtag);
            }

            i = j;
            if (i < n && !hashtag.empty() && s[i] == '#') {
                i++;
            }
        }

        cout << hashtags.size() << '\n';
        for (int i = 0; i < (int)hashtags.size(); i++) {
            cout << '#' << hashtags[i] << '\n';
        }
    }
}
