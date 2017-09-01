#include <bits/stdc++.h>

using namespace std;

vector<int> leftRotation(vector<int> &a, int d)
{
    int n = a.size();
    vector<int> b(n);

    for (int i = 0; i < n; i++) {
        b[i] = a[(i + d) % n];
    }

    return b;
}

int main()
{
    ios_base::sync_with_stdio(0);

    int n, d;
    cin >> n >> d;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> result = leftRotation(a, d);
    for (int i = 0; i < (int)result.size(); i++) {
        cout << result[i] << (i != (int)result.size() - 1 ? " " : "");
    }
    cout << endl;
}
