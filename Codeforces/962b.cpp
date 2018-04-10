#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);

    string s;
    cin >> s;

    int last = -1;
    long long students = 0;
    for (int i = 0; i < n; i++) {
        if (a == 0 && b == 0)
            break;

        if (s[i] == '*') {
            last = -1;
            continue;
        }

        if (last == -1) {
            if (a > b && a > 0) {
                a--;
                students++;
                last = 0;
            } else if (b > 0) {
                b--;
                students++;
                last = 1;
            }
        } else if (last == 0) {
            if (b > 0) {
                b--;
                students++;
                last = 1;
            } else {
                last = -1;
            }
        } else if (last == 1) {
            if (a > 0) {
                a--;
                students++;
                last = 0;
            } else {
                last = -1;
            }
        }
    }

    printf("%lld\n", students);

    return 0;
}
