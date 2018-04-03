/* Wall */

#include <bits/stdc++.h>

using namespace std;

int main() {
    int h, w;
    scanf("%d %d", &h, &w);

    int c[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            scanf("%d", &c[i][j]);
        }
    }

    int a[h][w];
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for (int k = 0; k < 10; k++) {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
            }
        }
    }

    int cost = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (a[i][j] != -1) {
                cost += c[a[i][j]][1];
            }
        }
    }
    printf("%d\n", cost);

    return 0;
}
