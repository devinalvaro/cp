#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<vector<char>> field(9, vector<char>(9));
    for (int i = 0; i < 9; i++) {
        cin >> ws;

        string line;
        getline(cin, line);

        int k = 0;
        for (int j = 0; j < (int)line.size(); j++) {
            if (j == 3 || j == 7)
                continue;

            field[i][k++] = line[j];

            if (k == 9)
                break;
        }
    }

    int x, y;
    cin >> x >> y;

    int vertical, horizontal;
    if (x % 3 == 0) {
        vertical = 6;
    } else if (x % 3 == 2) {
        vertical = 3;
    } else {
        vertical = 0;
    }
    if (y % 3 == 0) {
        horizontal = 6;
    } else if (y % 3 == 2) {
        horizontal = 3;
    } else {
        horizontal = 0;
    }

    int dot_count = 0;
    for (int i = vertical; i < vertical + 3; i++) {
        for (int j = horizontal; j < horizontal + 3; j++) {
            if (field[i][j] == '.') {
                dot_count++;

                field[i][j] = '!';
            }
        }
    }

    if (dot_count == 0) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (field[i][j] == '.') {
                    field[i][j] = '!';
                }
            }
        }
    }

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << field[i][j];

            if (j == 2 || j == 5) {
                cout << ' ';
            }
        }
        if (i == 2 || i == 5) {
            cout << '\n';
        }
        cout << '\n';
    }

    return 0;
}
