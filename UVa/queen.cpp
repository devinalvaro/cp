/* brute force : recursive backtracking */

#include <cstring>
#include <iomanip>
#include <iostream>
#include <stdio.h>
using namespace std;

int row[8], line, a, b;

bool canPlace(int r, int c)
{
    for (int i = 0; i < c; i++) {
        if (row[i] == r || abs(row[i] - r) == abs(i - c)) {
            return false;
        }
    }

    return true;
}

void backtrack(int c)
{
    if (c == 8 && row[b] == a) {
        printf("%2d      %d", ++line, row[0] + 1);

        for (int i = 1; i < 8; i++) {
            printf(" %d", row[i] + 1);
        }

        printf("\n");
    }

    for (int r = 0; r < 8; r++) {
        if (canPlace(r, c)) {
            row[c] = r;
            backtrack(c + 1);
        }
    }
}

int main()
{
    int tc;
    cin >> tc;

    while (tc--) {
        cin >> a >> b;
        a--;
        b--;
        line = 0;
        memset(row, 0, sizeof row);
        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");
        backtrack(0);

        if (tc) {
            cout << '\n';
        }
    }
}
