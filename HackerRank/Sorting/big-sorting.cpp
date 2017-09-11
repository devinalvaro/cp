#include <bits/stdc++.h>

using namespace std;

bool comp(const string &a, const string &b) {
    if (a.size() != b.size())
        return a.size() < b.size();
    return a < b;
}

int main()
{
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    vector<string> numerics(n);
    for (int i = 0; i < n; i++) {
        cin >> numerics[i];
    }

    sort(numerics.begin(), numerics.end(), comp);

    for (int i = 0; i < n; i++) {
        cout << numerics[i] << '\n';
    }
}
