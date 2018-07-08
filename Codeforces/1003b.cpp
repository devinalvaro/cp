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
    int a, b, x;
    cin >> a >> b >> x;

    bool swapped = false;
    if (b > a) {
        swap(a, b);
        swapped = true;
    }
    x += 1;

    ve<int> holder(x);
    while (a > 0) {
        for (int i = 0; i < x && a > 0; i += 2) {
            holder[i]++;
            a--;
        }
    }
    while (b > 0) {
        for (int i = 1; i < x && b > 0; i += 2) {
            holder[i]++;
            b--;
        }
    }

    for (int i = 0; i < x; i++) {
        while (holder[i]--) {
            cout << (i & 1 ? (swapped ? '0' : '1') : (swapped ? '1' : '0'));
        }
    }
    cout << endl;

    return 0;
}
