#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    map<int, int> a;
    int b;
    for (int i = 0; i < n; i++) {
        scanf("%d", &b);
        a[b] = i + 1;
    }

    if ((int)a.size() >= k) {
        printf("YES\n");

        int i = 0;
        for (auto it = a.begin(); it != a.end() && i < k; it++, i++) {
            printf("%d", it->second);
            if (i == k - 1) {
                printf("\n");
            } else {
                printf(" ");
            }
        }
    } else {
        printf("NO\n");
    }

    return 0;
}
