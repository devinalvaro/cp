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
    int n;
    scanf("%d", &n);

    string s;
    cin >> s;

    if (n == 1 && s[0] == '0') {
        printf("No\n");

        return 0;
    }

    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) {
            if (s[i] == '0' && i - 2 >= 0 && i < n - 1) {
                if (s[i - 2] == '1') {
                    continue;
                }
            }

            printf("No\n");

            return 0;
        }
    }

    printf("Yes\n");

    return 0;
}
