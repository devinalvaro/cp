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
    int n, k, l;
    scanf("%d %d %d", &n, &k, &l);

    vector<ll> a(n * k);
    for (int i = 0; i < n * k; i++) {
        scanf("%lld", &a[i]);
    }

    sort(a.begin(), a.end());

    if (k == 1) {
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            sum += a[i];

            if (a[i] - a[0] > l) {
                sum = 0;

                break;
            }
        }

        printf("%lld\n", sum);

        return 0;
    }

    int to_pick = upper_bound(a.begin(), a.end(), a[0] + l) - a.begin();

    if (to_pick < n) {
        printf("0\n");

        return 0;
    }

    ll sum = 0;
    int to_carry = to_pick - n;

    int i = 0;
    while (to_carry > 0) {
        if (i % k == 0) {
            sum += a[i];
        } else {
            to_carry--;
        }

        i++;
    }
    for (; i < to_pick; i++) {
        sum += a[i];
    }

    printf("%lld\n", sum);

    return 0;
}
