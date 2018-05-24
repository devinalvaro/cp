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

    priority_queue<ii, vii, greater<ii>> min_pq;
    priority_queue<ii> max_pq;

    for (int i = 0; i < n; i++) {
        int w;
        scanf("%d", &w);

        min_pq.push({w, i + 1});
    }

    string s;
    cin >> s;

    for (int i = 0; i < 2 * n; i++) {
        if (s[i] == '0') {
            ii t = min_pq.top();
            min_pq.pop();

            printf("%d", t.se);

            max_pq.push({t.fi, t.se});
        } else {
            ii t = max_pq.top();
            max_pq.pop();

            printf("%d", t.se);
        }

        if (i == (2 * n) - 1) {
            printf("\n");
        } else {
            printf(" ");
        }
    }

    return 0;
}
