#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    vector<int> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }

    sort(ar.begin(), ar.end());

    if (ar.size() & 1) {
        cout << ar[(int)ar.size() / 2] << '\n';
    } else {
        cout << (ar[((int)ar.size() / 2) - 1] + ar[(int)ar.size() / 2]) / 2
             << '\n';
    }
}
