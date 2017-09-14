#include <bits/stdc++.h>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, -1, 0, 1};

int main()
{
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<char>> grid(n, vector<char>(m));
        pair<int, int> start, end;
        for (int i = 0; i < n; i++) {
            string line;
            cin >> line;

            for (int j = 0; j < m; j++) {
                grid[i][j] = line[j];

                if (grid[i][j] == 'M') {
                    start = make_pair(i, j);
                }

                if (grid[i][j] == '*') {
                    end = make_pair(i, j);
                }
            }
        }

        int k;
        cin >> k;

        queue<vector<pair<int, int>>> pathQueue;
        pathQueue.push({start});

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        vector<pair<int, int>> currentPath;

        bool found = false;

        while (!pathQueue.empty() && !found) {
            currentPath = pathQueue.front();
            pathQueue.pop();

            visited[currentPath.back().first][currentPath.back().second] = true;

            for (int k = 0; k < 4; k++) {
                int r = currentPath.back().first + dr[k];
                int c = currentPath.back().second + dc[k];

                if (r >= 0 && r < n && c >= 0 && c < m && grid[r][c] != 'X' &&
                    !visited[r][c]) {
                    currentPath.push_back(make_pair(r, c));

                    if (r == end.first && c == end.second) {
                        found = true;

                        break;
                    }

                    pathQueue.push(currentPath);

                    currentPath.pop_back();
                }
            }
        }

        int guess = 0;

        for (int i = 0; i < (int)currentPath.size() - 1; i++) {
            int roads = 0;
            for (int k = 0; k < 4; k++) {
                int r = currentPath[i].first + dr[k];
                int c = currentPath[i].second + dc[k];

                if (r >= 0 && r < n && c >= 0 && c < m && grid[r][c] != 'X') {
                    roads++;
                }
            }

            if (roads > 2) {
                guess += 1;
            }
        }

        if (guess == k) {
            cout << "Impressed\n";
        } else {
            cout << "Oops!\n";
        }
    }
}
