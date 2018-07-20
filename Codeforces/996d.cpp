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
    n *= 2;

    ve<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int swap = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            continue;
        }

        for (int j = i + 1; j < n; j++) {
            if (a[i] != a[j]) {
                if (a[j] != 0) {
                    swap++;
                }
                continue;
            }

            a[j] = 0;
            break;
        }
    }
    cout << swap << endl;

    return 0;
}
