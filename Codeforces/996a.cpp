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

    int s = 0;
    s += n / 100; n %= 100;
    s += n / 20; n %= 20;
    s += n / 10; n %= 10;
    s += n / 5; n %= 5;
    s += n / 1; n %= 1;
    cout << s << endl;

    return 0;
}
