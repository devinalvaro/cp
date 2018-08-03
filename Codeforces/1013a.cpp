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

    int xum = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        xum += x;
    }

    int yum = 0;
    for (int i = 0; i < n; i++) {
        int y;
        cin >> y;

        yum += y;
    }

    if (xum < yum) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
    }

    return 0;
}
