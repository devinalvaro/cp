/* brute force : backtracking */

#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;

bool valid(vector<int> &row, int r, int col)
{
    for (int c = 0; c < col; c++) {
        if (row[c] == r || abs(row[c] - r) == abs(c - col))
            return false;
    }

    return true;
}

int backtrack(vector<int> &ori_row, vector<int> &row, int col)
{
    if (col == 8)
        return 0;

    int moves = 1e9;

    for (int r = 0; r < 8; r++) {
        if (valid(row, r, col)) {
            row[col] = r;

            moves = min(moves, (r == ori_row[col] ? 0 : 1) +
                                   backtrack(ori_row, row, col + 1));
        }
    }

    return moves;
}

int main()
{
    ios_base::sync_with_stdio(0);

    int tc = 0;

    vector<int> ori_row(8);

    while (cin >> ori_row[0]) {
        ori_row[0]--;

        for (int i = 1; i < 8; i++) {
            cin >> ori_row[i];
            ori_row[i]--;
        }

        vector<int> row(8);

        cout << "Case " << ++tc << ": " << backtrack(ori_row, row, 0) << '\n';
    }
}
