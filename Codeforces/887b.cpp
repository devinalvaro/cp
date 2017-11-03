#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> cubes(n, vector<int>(6));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 6; j++) {
            cin >> cubes[i][j];
        }
    }

    set<int> numbers;
    numbers.insert(0);

    if (n == 1) {
        for (int i = 0; i < 6; i++) {
            numbers.insert(cubes[0][i]);
        }
    } else if (n == 2) {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 6; j++) {
                numbers.insert((cubes[0][i]));

                numbers.insert((cubes[1][j]));

                numbers.insert((10 * cubes[0][i]) + cubes[1][j]);

                numbers.insert((10 * cubes[1][j]) + cubes[0][i]);
            }
        }
    } else if (n == 3) {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 6; j++) {
                for (int k = 0; k < 6; k++) {
                    numbers.insert((cubes[0][i]));

                    numbers.insert((cubes[1][j]));

                    numbers.insert((cubes[2][k]));

                    numbers.insert((10 * cubes[0][i]) + cubes[1][j]);

                    numbers.insert((10 * cubes[0][i]) + cubes[2][k]);

                    numbers.insert((10 * cubes[1][j]) + cubes[0][i]);

                    numbers.insert((10 * cubes[1][j]) + cubes[2][k]);

                    numbers.insert((10 * cubes[2][k]) + cubes[0][i]);

                    numbers.insert((10 * cubes[2][k]) + cubes[1][j]);

                    numbers.insert((100 * cubes[0][i]) + (10 * cubes[1][j]) +
                                   cubes[2][k]);

                    numbers.insert((100 * cubes[0][i]) + (10 * cubes[2][k]) +
                                   cubes[1][j]);

                    numbers.insert((100 * cubes[1][j]) + (10 * cubes[0][i]) +
                                   cubes[2][k]);

                    numbers.insert((100 * cubes[1][j]) + (10 * cubes[2][k]) +
                                   cubes[0][i]);

                    numbers.insert((100 * cubes[2][k]) + (10 * cubes[0][i]) +
                                   cubes[1][j]);

                    numbers.insert((100 * cubes[2][k]) + (10 * cubes[1][j]) +
                                   cubes[0][i]);
                }
            }
        }
    }

    auto it = numbers.begin();

    while (next(it) != numbers.end()) {
        if (*next(it) - *it > 1) {
            cout << *it << '\n';

            return 0;
        }

        it = next(it);
    }

    cout << *it << '\n';

    return 0;
}
