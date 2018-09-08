/* KATHTHI */

#include <bits/stdc++.h>

using namespace std;

int dr[4] = {0, 1, -1, 0};
int dc[4] = {1, 0, 0, -1};

bool is_valid(int r, int c, int R, int C) {
    return r >= 0 && r < R && c >= 0 && c < C;
}

char prison[1010][1010];
int dist[1010][1010];

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int r, c;
        scanf("%d %d", &r, &c);

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                scanf(" %c", &prison[i][j]);

                dist[i][j] = INT_MAX;
            }
        }
        dist[0][0] = 0;

        deque<pair<int, int>> q;
        q.push_front(make_pair(0, 0));

        while (!q.empty()) {
            int y1 = q.front().first;
            int x1 = q.front().second;
            q.pop_front();

            for (int i = 0; i < 4; i++) {
                int y2 = y1 + dr[i];
                int x2 = x1 + dc[i];

                if (is_valid(x2, y2, r, c)) {
                    int cost = prison[x1][y1] != prison[x2][y2];

                    if (dist[x2][y2] > dist[x1][y1] + cost) {
                        dist[x2][y2] = dist[x1][y1] + cost;

                        if (cost) {
                            q.push_back(make_pair(y2, x2));
                        } else {
                            q.push_front(make_pair(y2, x2));
                        }
                    }
                }
            }
        }

        printf("%d\n", dist[r - 1][c - 1]);
    }

    return 0;
}
