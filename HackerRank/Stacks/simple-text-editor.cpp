#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);

    int q;
    cin >> q;

    string s;
    stack<pair<int, pair<int, string>>> undo;

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            string w;
            cin >> w;

            s += w;

            undo.push(make_pair(type, make_pair(w.size(), "")));
        } else if (type == 2) {
            int k;
            cin >> k;

            string w = s.substr(s.size() - k);
            s.erase(s.size() - k);

            undo.push(make_pair(type, make_pair(0, w)));
        } else if (type == 3) {
            int k;
            cin >> k;

            cout << s[k - 1] << '\n';
        } else if (type == 4) {
            if (undo.top().first == 1) {
                s.erase(s.size() - undo.top().second.first);
            } else if (undo.top().first == 2) {
                s += undo.top().second.second;
            }

            undo.pop();
        }
    }
}
