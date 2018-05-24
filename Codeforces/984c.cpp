#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int main() {
    int n;
    scanf("%d", &n);

    while (n--) {
        ll p, q, b;
        scanf("%lld %lld %lld", &p, &q, &b);

        q /= __gcd(p, q);

        ll g = __gcd(q, b);
        while (g > 1) {
            while (q % g == 0) {
                q /= g;
            }
            g = __gcd(b, q);
        }

        if (q != 1) {
            printf("Infinite\n");
        } else {
            printf("Finite\n");
        }
    }

    return 0;
}
