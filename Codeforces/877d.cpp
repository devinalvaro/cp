#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<char>> room(n, vector<char>(m));
    vector<set<int>> row_set(n, set<int>()), col_set(m, set<int>());

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> room[i][j];

            row_set[i].insert(j);
            col_set[j].insert(i);
        }
    }

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x1--, y1--, x2--, y2--;

    vector<vector<int>> dist(n, vector<int>(m, -1));
    dist[x1][y1] = 0;

    row_set[x1].erase(y1);
    col_set[y1].erase(x1);

    queue<pair<int, int>> q;
    q.push(make_pair(x1, y1));

    while (!q.empty()) {
        pair<int, int> u = q.front();
        q.pop();

        int x = u.first, y = u.second;

        if (x == x2 && y == y2) {
            cout << dist[x][y] << '\n';

            return 0;
        }

        if (!row_set[x].empty()) {
            auto right = row_set[x].lower_bound(y), left = right;

            vector<int> to_erase;

            while (right != row_set[x].end()) {
                if (*right - y > k || room[x][*right] == '#')
                    break;

                q.push(make_pair(x, *right));
                if (dist[x][*right] == -1) {
                    dist[x][*right] = dist[x][y] + 1;
                }
                to_erase.push_back(*right);

                right = next(right);
            }

            while (left != row_set[x].begin()) {
                left = prev(left);

                if (y - *left > k || room[x][*left] == '#')
                    break;

                q.push(make_pair(x, *left));
                if (dist[x][*left] == -1) {
                    dist[x][*left] = dist[x][y] + 1;
                }
                to_erase.push_back(*left);
            }

            for (int e : to_erase) {
                row_set[x].erase(e);
            }
        }

        if (!col_set[y].empty()) {
            auto high = col_set[y].lower_bound(x), low = high;

            vector<int> to_erase;

            while (high != col_set[y].end()) {
                if (*high - x > k || room[*high][y] == '#')
                    break;

                q.push(make_pair(*high, y));
                if (dist[*high][y] == -1) {
                    dist[*high][y] = dist[x][y] + 1;
                }
                to_erase.push_back(*high);

                high = next(high);
            }

            while (low != col_set[y].begin()) {
                low = prev(low);

                if (x - *low > k || room[*low][y] == '#')
                    break;

                q.push(make_pair(*low, y));
                if (dist[*low][y] == -1) {
                    dist[*low][y] = dist[x][y] + 1;
                }
                to_erase.push_back(*low);
            }

            for (int e : to_erase) {
                col_set[y].erase(e);
            }
        }
    }

    cout << -1 << '\n';

    return 0;
}
