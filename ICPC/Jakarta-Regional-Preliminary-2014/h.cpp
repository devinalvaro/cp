#include <bits/stdc++.h>

using namespace std;

int main() {
    int m;
    cin >> m;

    unordered_map<int, pair<int, int>> votes;
    unordered_map<int, int> parent;
    parent[0] = -1;

    while (m--) {
        int p, n;
        cin >> p >> n;

        for (int i = 0; i < n; i++) {
            int c;
            cin >> c;

            parent[c] = p;
        }
    }

    int q;
    cin >> q;

    while (q--) {
        int r;
        cin >> r;

        if (r == -1) {
            cin >> r;
            cout << votes[r].first << ' ' << votes[r].second << '\n';
        } else {
            int v1, v2;
            cin >> v1 >> v2;

            int p = r;
            while (p != -1) {
                votes[p].first += v1;
                votes[p].second += v2;

                p = parent[p];
            }
        }
    }
}
