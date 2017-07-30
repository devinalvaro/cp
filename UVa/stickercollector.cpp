/* graph : graph traversal */

#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

char area[200][200], orientation;
int n, m, stickers;
pair<int, int> pos;

void run(char inst)
{
    if (inst == 'D') {
        if (orientation == 'N') {
            orientation = 'L';
        } else if (orientation == 'S') {
            orientation = 'O';
        } else if (orientation == 'L') {
            orientation = 'S';
        } else if (orientation == 'O') {
            orientation = 'N';
        }
    } else if (inst == 'E') {
        if (orientation == 'N') {
            orientation = 'O';
        } else if (orientation == 'S') {
            orientation = 'L';
        } else if (orientation == 'L') {
            orientation = 'N';
        } else if (orientation == 'O') {
            orientation = 'S';
        }
    } else {
        if (orientation == 'N') {
            if (pos.first != 0 && area[pos.first - 1][pos.second] != '#') {
                pos = make_pair(pos.first - 1, pos.second);
            }
        } else if (orientation == 'S') {
            if (pos.first != n - 1 && area[pos.first + 1][pos.second] != '#') {
                pos = make_pair(pos.first + 1, pos.second);
            }
        } else if (orientation == 'L') {
            if (pos.second != m - 1 && area[pos.first][pos.second + 1] != '#') {
                pos = make_pair(pos.first, pos.second + 1);
            }
        } else if (orientation == 'O')
            if (pos.second != 0 && area[pos.first][pos.second - 1] != '#') {
                pos = make_pair(pos.first, pos.second - 1);
            }
    }
}

int main()
{
    int s;
    string inst;

    while (cin >> n >> m >> s) {
        if (n == 0 && m == 0 && s == 0) {
            break;
        }

        memset(area, 0, sizeof(area));
        stickers = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> area[i][j];

                if (area[i][j] == 'N' || area[i][j] == 'S' || area[i][j] == 'L'
                    || area[i][j] == 'O') {
                    orientation = area[i][j];
                    pos = make_pair(i, j);
                }
            }
        }

        cin >> inst;

        for (int i = 0; i < s; i++) {
            run(inst[i]);

            if (area[pos.first][pos.second] == '*') {
                stickers++;
                area[pos.first][pos.second] = '.';
            }
        }

        cout << stickers << '\n';
    }
}
