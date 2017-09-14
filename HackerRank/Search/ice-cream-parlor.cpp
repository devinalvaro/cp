#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        int m, n;
        cin >> m >> n;

        vector<int> c(n);
        for (int i = 0; i < n; i++) {
            cin >> c[i];
        }

        unordered_map<int, int> complementID;
        for (int i = 0; i < n; i++) {
            complementID[c[i]] = i;
        }

        for (int i = 0; i < n; i++) {
            if (complementID.find(m - c[i]) != complementID.end() &&
                i != complementID[m - c[i]]) {
                cout << i + 1 << ' ' << complementID[m - c[i]] + 1 << '\n';

                break;
            }
        }
    }
}
