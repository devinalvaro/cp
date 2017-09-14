#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    for (int a = 1; a < n; a++) {
        for (int b = 1; b < n; b++) {
            int dr[] = {-a, -b, -b, -a, a, b, b, a};
            int dc[] = {-b, -a, a, b, b, a, -a, -b};

            queue<pair<int, int>> squares;
            squares.push(make_pair(0, 0));

            vector<vector<int>> dist(n, vector<int>(n, -1));
            dist[0][0] = 0;

            while (!squares.empty()) {
                pair<int, int> u = squares.front();
                squares.pop();

                if (u.first == n - 1 && u.second == n - 1)
                    break;

                for (int k = 0; k < 8; k++) {
                    int i = u.first + dr[k];
                    int j = u.second + dc[k];

                    if (i >= 0 && i < n && j >= 0 && j < n &&
                        dist[i][j] == -1) {
                        dist[i][j] = dist[u.first][u.second] + 1;

                        squares.push(make_pair(i, j));
                    }
                }
            }

            cout << dist[n - 1][n - 1] << ' ';
        }

        cout << '\n';
    }
}
