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

    set<int> cb;
    for (int i = 0; i < n; i++) {
        int p;
        scanf("%d", &p);

        cb.insert(p - 1);
    }

    int i = 0, b = 0, w = 0;
    for (auto it = cb.begin(); it != cb.end(); it++) {
        b += abs(*it - i);
        w += abs(*it - (i + 1));

        i += 2;
    }

    printf("%d\n", min(b, w));

    return 0;
}
