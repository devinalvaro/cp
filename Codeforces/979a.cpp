#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ll long long
#define ve vector
#define ii pair<int, int>
#define iv pair<int, ii>

int main() {
    ll n;
    cin >> n;

    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    n += 1;
    if (n & 1) {
        cout << n << endl;
    } else {
        cout << n / 2 << endl;
    }

    return 0;
}
