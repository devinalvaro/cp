#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int main() {
    int x, y;
    scanf("%d %d", &x, &y);

    if (x == y) {
        printf("=\n");
        return 0;
    }

    if (x == 1) {
        printf("<\n");
        return 0;
    } else if (y == 1) {
        printf(">\n");
        return 0;
    }

    if (x == 2 && y == 3) {
        printf("<\n");
        return 0;
    } else if (x == 3 && y == 2) {
        printf(">\n");
        return 0;
    }

    if ((x == 2 && y == 4) || (x == 4 && y == 2)) {
        printf("=\n");
        return 0;
    }

    if (x < y) {
        printf(">\n");
    } else {
        printf("<\n");
    }

    return 0;
}
