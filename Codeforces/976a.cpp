#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    string s;
    cin >> s;

    if (s == "0") {
        printf("0\n");

        return 0;
    }

    int z = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            z++;
        }
    }

    printf("1");
    for (int i = 0; i < z; i++) {
        printf("0");
    }
    printf("\n");

    return 0;
}
