#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> maze(n, vector<char>(m));

    pair<int, int> start, end;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maze[i][j];

            if (maze[i][j] == 'S') {
                start = make_pair(i, j);
            }
            if (maze[i][j] == 'E') {
                end = make_pair(i, j);
            }
        }
    }

    string s;
    cin >> s;

    vector<int> directions = {'d', 'l', 'r', 'u'};
    sort(directions.begin(), directions.end());

    int number = 0;

    do {
        pair<int, int> position = start;

        for (char c : s) {
            if (directions[c - '0'] == 'd') {
                position.first += 1;
            } else if (directions[c - '0'] == 'l') {
                position.second -= 1;
            } else if (directions[c - '0'] == 'r') {
                position.second += 1;
            } else if (directions[c - '0'] == 'u') {
                position.first -= 1;
            }

            if (position == end) {
                number += 1;

                break;
            }
            if (position.first < 0 || position.first >= n ||
                position.second < 0 || position.second >= m ||
                maze[position.first][position.second] == '#') {
                break;
            }
        }
    } while (next_permutation(directions.begin(), directions.end()));

    cout << number << '\n';

    return 0;
}
