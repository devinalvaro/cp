/* ALL IZZ WELL **/

#include <bits/stdc++.h>

using namespace std;

int dr[8] = {0, 1, -1, 0, 1, -1, 1, -1};
int dc[8] = {1, 0, 0, -1, 1, -1, -1, 1};

bool is_valid(int r, int c, vector<vector<char>> &matrix) {
    return r >= 0 && r < (int)matrix.size() && c >= 0 &&
           c < (int)matrix[0].size();
}

bool dfs(int r, int c, vector<vector<char>> &matrix,
         vector<vector<bool>> &visited, int k, string &allizzwell) {
    visited[r][c] = true;

    if (k + 1 >= (int)allizzwell.size())
        return true;

    for (int i = 0; i < 8; i++) {
        if (!is_valid(r + dr[i], c + dc[i], matrix))
            continue;

        if (matrix[r + dr[i]][c + dc[i]] == allizzwell[k + 1] &&
            !visited[r + dr[i]][c + dc[i]]) {
            if (dfs(r + dr[i], c + dc[i], matrix, visited, k + 1, allizzwell))
                return true;
        }
    }
    
    visited[r][c] = false;

    return false;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;

        vector<vector<char>> matrix(r, vector<char>(c));
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        vector<vector<bool>> visited(r, vector<bool>(false));

        bool loop = true;
        for (int i = 0; i < r && loop; i++) {
            for (int j = 0; j < c && loop; j++) {
                if (matrix[i][j] == 'A') {
                    for (int i = 0; i < r; i++) {
                        for (int j = 0; j < c; j++) {
                            visited[i][j] = false;
                        }
                    }

                    string allizzwell = "ALLIZZWELL";
                    if (dfs(i, j, matrix, visited, 0, allizzwell)) {
                        cout << "YES\n";

                        loop = false;
                    }
                }
            }
        }

        if (loop) {
            cout << "NO\n";
        }
    }

    return 0;
}
