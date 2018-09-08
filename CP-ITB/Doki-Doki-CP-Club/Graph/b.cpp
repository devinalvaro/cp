/* Dungeon Master */

#include <bits/stdc++.h>

using namespace std;

int dl[10] = {1, -1, 0, 0, 0, 0};
int dr[10] = {0, 0, 0, 1, -1, 0};
int dc[10] = {0, 0, 1, 0, 0, -1};

bool is_valid(int ll, int rr, int cc, int l, int r, int c,
              vector<vector<vector<char>>> &dungeon) {
    return ll >= 0 && ll < l && rr >= 0 && rr < r && cc >= 0 && cc < c &&
           dungeon[ll][rr][cc] != '#';
}

int main() {
    int l, r, c;

    while (cin >> l >> r >> c) {
        if (l == 0 && r == 0 && c == 0)
            break;

        vector<vector<vector<char>>> dungeon(
            l, vector<vector<char>>(r, vector<char>(c)));

        int sl, sr, sc;
        int el, er, ec;
        for (int k = 0; k < l; k++) {
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    cin >> dungeon[k][i][j];

                    if (dungeon[k][i][j] == 'S') {
                        sl = k;
                        sr = i;
                        sc = j;
                    }
                    if (dungeon[k][i][j] == 'E') {
                        el = k;
                        er = i;
                        ec = j;
                    }
                }
            }
        }

        queue<pair<int, pair<int, int>>> q;
        q.push(make_pair(sl, make_pair(sr, sc)));

        vector<vector<vector<int>>> dist(
            l, vector<vector<int>>(r, vector<int>(c, INT_MAX)));

        dist[sl][sr][sc] = 0;

        while (!q.empty()) {
            int ll = q.front().first;
            int rr = q.front().second.first;
            int cc = q.front().second.second;
            q.pop();

            for (int i = 0; i < 6; i++) {
                if (is_valid(ll + dl[i], rr + dr[i], cc + dc[i], l, r, c,
                             dungeon)) {
                    if (dist[ll + dl[i]][rr + dr[i]][cc + dc[i]] == INT_MAX) {
                        dist[ll + dl[i]][rr + dr[i]][cc + dc[i]] =
                            dist[ll][rr][cc] + 1;

                        q.push(make_pair(ll + dl[i],
                                         make_pair(rr + dr[i], cc + dc[i])));
                    }
                }
            }
        }

        if (dist[el][er][ec] == INT_MAX) {
            cout << "Trapped!\n";
        } else {
            cout << "Escaped in " << dist[el][er][ec] << " minute(s).\n";
        }
    }

    return 0;
}
