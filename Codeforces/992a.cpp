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

    set<int> s;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        if (a != 0) {
            s.insert(a);
        }
    }

    cout << s.size() << endl;

    return 0;
}
