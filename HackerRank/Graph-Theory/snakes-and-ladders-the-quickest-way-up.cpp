#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        vector<int> board(101, 0);
        for (int i = 1; i <= 100; i++) {
            board[i] = i;
        }

        int n;
        cin >> n;

        while (n--) {
            int s, e;
            cin >> s >> e;

            board[s] = e;
        }

        int m;
        cin >> m;

        while (m--) {
            int s, e;
            cin >> s >> e;

            board[s] = e;
        }

        vector<int> dist(101, -1);
        dist[1] = 0;

        queue<int> squares;
        squares.push(1);

        while (!squares.empty()) {
            int u = squares.front();
            squares.pop();

            for (int i = 1; i <= 6; i++) {
                if (u + i > 100)
                    break;

                int v = board[u + i];
                while (board[v] != v) {
                    v = board[v];
                }

                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;

                    squares.push(v);
                }
            }
        }

        cout << dist[100] << '\n';
    }
}
