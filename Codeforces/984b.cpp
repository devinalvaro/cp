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

int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool is_valid(int r, int c, int n, int m) {
    return r >= 0 && r < n && c >= 0 && c < m;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '*') {
                continue;
            }

            int b = (grid[i][j] == '.' ? 0 : grid[i][j] - '0');
            for (int k = 0; k < 8; k++) {
                int ii = i + dr[k];
                int jj = j + dc[k];

                if (!is_valid(ii, jj, n, m)) {
                    continue;
                }

                if (grid[ii][jj] == '*') {
                    b--;
                }
            }

            if (b != 0) {
                printf("NO\n");

                return 0;
            }
        }
    }

    printf("YES\n");

    return 0;
}
