/* graph : flood fill */

#include <iostream>
using namespace std;

int n, dr[] = {1, 0, -1, 0}, dc[] = {0, 1, 0, -1};
char area[120][120];

int floodFill(int r, int c)
{
    if (r < 0 || r >= n || c < 0 || c >= n) {
        return 0;
    }

    if (area[r][c] != 'x' && area[r][c] != '@') {
        return 0;
    }

    int live = area[r][c] == 'x' ? 1 : 0;
    area[r][c] = '#';

    for (int i = 0; i < 4; i++) {
        live += floodFill(r + dr[i], c + dc[i]);
    }

    return live;
}

int main()
{
    int tc;
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        cin >> n;
        string s;

        for (int i = 0; i < n; i++) {
            cin >> s;

            for (int j = 0; j < n; j++) {
                area[i][j] = s[j];
            }
        }

        int alive = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int live = floodFill(i, j);

                if (live >= 1) {
                    alive++;
                }
            }
        }

        cout << "Case " << t << ": " << alive << '\n';
    }
}
