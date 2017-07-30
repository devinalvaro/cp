#include <iostream>
#include <map>

using namespace std;

map<char, int> weights;

int main()
{
    weights['Q'] = 9;
    weights['R'] = 5;
    weights['N'] = 3;
    weights['B'] = 3;
    weights['P'] = 1;

    string board;
    int score = 0;

    for (int i = 0; i < 8; i++) {
        cin >> board;
        for (int j = 0; j < 8; j++) {
            if (board[j] == '.')
                continue;

            score += (islower(board[j]) ? -1 : 1) * weights[toupper(board[j])];
        }
    }

    if (score > 0) {
        cout << "White" << endl;
    } else if (score < 0) {
        cout << "Black" << endl;
    } else {
        cout << "Draw" << endl;
    }
}
