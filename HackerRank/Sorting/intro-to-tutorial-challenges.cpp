#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);

    int v, n;
    cin >> v >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << find(a.begin(), a.end(), v) - a.begin() << '\n';
}
