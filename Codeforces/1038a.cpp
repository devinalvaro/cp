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

    ve<int> letters(k);
    for (int i = 0; i < n; i++) {
        letters[s[i] - 'A']++;
    }

    int mn = *min_element(letters.begin(), letters.end());
    cout << k * mn << endl;

    return 0;
}
