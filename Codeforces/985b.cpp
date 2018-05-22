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
    int n, m;
    scanf("%d %d", &n, &m);

    vector<string> s(n);
    vector<int> sw(m, 0);

    for (int i = 0; i < n; i++) {
        cin >> s[i];

        for (int j = 0; j < m; j++) {
            if (s[i][j] == '1') {
                sw[j]++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        bool important = false;

        for (int j = 0; j < m; j++) {
            if (s[i][j] == '1' && sw[j] == 1) {
                important = true;
            }
        }

        if (!important) {
            printf("YES\n");

            return 0;
        }
    }
    
    printf("NO\n");

    return 0;
}
