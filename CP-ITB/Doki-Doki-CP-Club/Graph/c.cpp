/* The Labyrinth */

#include <bits/stdc++.h>

using namespace std;

int n, m;
int sz;
char field[1000][1000];
int size[1000][1000];
int turn[1000][1000];
bool visited[1000][1000];
vector<pair<int, int>> components;

bool valid(int r, int c) {
    return r >= 0 && r < n && c >= 0 && c < m && field[r][c] == '.';
}

void dfs(int r, int c) {
    if (!valid(r, c) || visited[r][c])
        return;

    sz++;
    visited[r][c] = true;
    components.push_back(make_pair(r, c));

    dfs(r + 1, c);
    dfs(r, c + 1);
    dfs(r - 1, c);
    dfs(r, c - 1);
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf(" %c", &field[i][j]);
        }
    }

    int t = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (field[i][j] == '.') {
                sz = 0;
                dfs(i, j);

                ++t;
                for (pair<int, int> v : components) {
                    size[v.first][v.second] = sz;
                    turn[v.first][v.second] = t;
                }

                components.clear();
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (field[i][j] == '.') {
                printf(".");
                continue;
            }

            int up = -1, down = -1, left = -1, right = -1;
            if (valid(i - 1, j))
                up = turn[i - 1][j];
            if (valid(i + 1, j))
                down = turn[i + 1][j];
            if (valid(i, j - 1))
                left = turn[i][j - 1];
            if (valid(i, j + 1))
                right = turn[i][j + 1];

            int sz = 1;
            if (up != -1)
                sz += size[i - 1][j];
            if (down != -1 && down != up)
                sz += size[i + 1][j];
            if (left != -1 && left != down && left != up)
                sz += size[i][j - 1];
            if (right != -1 && right != left && right != down && right != up)
                sz += size[i][j + 1];

            printf("%d", sz % 10);
        }
        printf("\n");
    }

    return 0;
}
