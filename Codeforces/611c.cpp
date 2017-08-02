#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    int h, w;
    cin >> h >> w;

    vector<vector<char>> field(h, vector<char>(w));
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            cin >> field[i][j];

    vector<vector<int>> row(h, vector<int>(w)), col(h, vector<int>(w));
    for (int i = 0; i < h; i++)
        for (int j = 1; j < w; j++)
            row[i][j] =
                row[i][j - 1] + (field[i][j] == '.' && field[i][j - 1] == '.');
    for (int j = 0; j < w; j++)
        for (int i = 1; i < h; i++)
            col[i][j] =
                col[i - 1][j] + (field[i][j] == '.' && field[i - 1][j] == '.');

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        r1--;
        c1--;
        r2--;
        c2--;

        int ways = 0;
        for (int i = r1; i <= r2; i++) {
            ways += row[i][c2] - row[i][c1];
        }
        for (int j = c1; j <= c2; j++) {
            ways += col[r2][j] - col[r1][j];
        }

        cout << ways << '\n';
    }
}
