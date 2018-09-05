#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define ll long long
#define ve vector
#define pq priority_queue
#define um unordered_map
#define us unordered_set

#define pii pair<int, int>
#define pll pair<ll, ll>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    string s;
    cin >> s;

    k /= 2;

    int skip = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            if (k > 0) {
                k--;
                printf("(");
            } else {
                skip++;
            }
        }
        if (s[i] == ')') {
            if (skip > 0) {
                skip--;
            } else {
                printf(")");
            }
        }
    }
    printf("\n");

    return 0;
}
