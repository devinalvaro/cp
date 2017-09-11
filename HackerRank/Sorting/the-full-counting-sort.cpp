#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    vector<pair<int, pair<int, string>>> a(n);
    for (int i = 0; i < n; i++) {
        int x;
        string s;
        cin >> x >> s;

        a[i] = make_pair(x, make_pair(i, s));
    }

    stable_sort(a.begin(), a.end());

    for (int i = 0; i < n; i++) {
        if (a[i].second.first < n / 2) {
            cout << '-';
        } else {
            cout << a[i].second.second;
        }
        cout << (i == n - 1 ? '\n' : ' ');
    }
}
