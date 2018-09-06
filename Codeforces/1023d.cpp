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

    ve<int> a(n);
    us<int> zeroes;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);

        if (a[i] == 0) {
            a[i] = 1;
            zeroes.insert(i);
        }
    }

    map<int, int> left, right;
    for (int i = 0; i < n; i++) {
        if (left.find(a[i]) == left.end()) {
            left[a[i]] = i;
        }
        right[a[i]] = i;
    }

    set<int> currents;
    for (int i = 0; i < n; i++) {
        if (left[a[i]] == i) {
            currents.insert(a[i]);
        }

        if (zeroes.find(i) != zeroes.end()) {
            a[i] = *currents.rbegin();
        }
        if (a[i] != *currents.rbegin()) {
            printf("NO\n");
            return 0;
        }

        if (right[a[i]] == i) {
            currents.erase(a[i]);
        }
    }

    if (*max_element(a.begin(), a.end()) != k) {
        if (zeroes.size() > 0) {
            a[*zeroes.begin()] = k;
        } else {
            printf("NO\n");
            return 0;
        }
    }

    printf("YES\n%d", a[0]);
    for (int i = 1; i < n; i++) {
        printf(" %d", a[i]);
    }
    printf("\n");
}
