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
    multiset<string> ms;

    int n;
    cin >> n;

    int cnt = 0;

    for (int i = 0; i < n; i++) {
        string size;
        cin >> size;

        ms.insert(size);
    }
    for (int i = 0; i < n; i++) {
        string size;
        cin >> size;

        auto it = ms.find(size);
        if (it != ms.end()) {
            ms.erase(it);
        } else {
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}
