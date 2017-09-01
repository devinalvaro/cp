#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);

    int n, a, b;
    cin >> n >> a >> b;
    a--;
    b--;

    string s;
    cin >> s;

    if (s[a] == s[b]) {
        cout << 0 << '\n';
    } else {
        cout << 1 << '\n';
    }
}
