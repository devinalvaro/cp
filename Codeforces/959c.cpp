#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    if (n == 2 || n == 3 || n == 4 || n == 5) {
        printf("-1\n");
    } else {
        for (int i = 2; i < (n / 2) + 2; i++) {
            printf("1 %d\n", i);
        }
        for (int i = (n / 2) + 2; i <= n; i++) {
            printf("2 %d\n", i);
        }
    }

    for (int i = 2; i <= n; i++) {
        printf("1 %d\n", i);
    }

    return 0;
}
