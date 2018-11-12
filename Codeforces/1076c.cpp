#include <bits/stdc++.h>

using namespace std;

#define fi  first
#define se  second
#define pb  push_back
#define ll  long long
#define ve  vector
#define pq  priority_queue
#define um  unordered_map
#define us  unordered_set
#define pii pair<int, int>
#define pll pair<ll, ll>

#define ceil(x, y) ((x + y - 1) / y)
#define spnl(i, n) (i == n - 1 ? '\n' : ' ')
#define nend(i, c) (i == c.end() ? i : next(i))

const double eps = 1e-9;

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        double d;
        scanf("%lf", &d);

        double l = 0, r = d, a, b;
        bool found = false;

        int it = 50;
        while (it--) {
            a = (l + r) / 2.0;
            b = d - a;
            double c = a * b;

            if (fabs(c - d) <= eps) {
                found = true;
            } else if (c + eps < d) {
                r = a;
            } else {
                l = a;
            }
        }

        if (found) {
            printf("Y %.9lf %.9lf\n", a, b);
        } else {
            printf("N\n");
        }
    }

    return 0;
}
