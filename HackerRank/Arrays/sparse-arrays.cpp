#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    vector<string> strings;
    while (n--) {
        string s;
        cin >> s;

        strings.push_back(s);
    }

    int q;
    cin >> q;

    while (q--) {
        string s;
        cin >> s;

        int occurence = 0;
        for (int i = 0; i < (int)strings.size(); i++) {
            if (strings[i] == s) {
                occurence++;
            }
        }
        cout << occurence << '\n';
    }
}
