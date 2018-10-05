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
    int n;
    cin >> n;

    if (n % 3 == 0) {
        printf("%d %d %d", 1, 1, n - 2);
    }
    if (n % 3 == 1) {
        printf("%d %d %d", 1, 1, n - 2);
    }
    if (n % 3 == 2) {
        printf("%d %d %d", 1, 2, n - 3);
    }
    printf("\n");

    return 0;
}
