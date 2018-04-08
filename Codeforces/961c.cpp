#include <bits/stdc++.h>

using namespace std;

int n;
int a[4][100][100];

int check(int k, int c) {
    int diff = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            diff += (a[k][i][j] != c);

            c ^= 1;
        }
    }
    return diff;
}

int main() {
    scanf("%d", &n);

    for (int k = 0; k < 4; k++) {

        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;

            for (int j = 0; j < n; j++) {
                if (s[j] == '0') {
                    a[k][i][j] = 0;
                } else if (s[j] == '1') {
                    a[k][i][j] = 1;
                }
            }
        }
    }

    int zeros[4];
    for (int k = 0; k < 4; k++) {
        zeros[k] = check(k, 0);
    }
    int ones[4];
    for (int k = 0; k < 4; k++) {
        ones[k] = check(k, 1);
    }

    int result = INT_MAX;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (i == j)
                continue;

            int a, b;
            for (int k = 0; k < 4; k++) {
                if (k != i && k != j) {
                    a = k;
                    break;
                }
            }
            for (int k = 0; k < 4; k++) {
                if (k != i && k != j && k != a) {
                    b = k;
                    break;
                }
            }

            result = min(result, zeros[i] + zeros[j] + ones[a] + ones[b]);
        }
    }
    printf("%d\n", result);

    return 0;
}
