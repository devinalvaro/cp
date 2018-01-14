#include <bits/stdc++.h>

using namespace std;

bool findPermutation(string &a, string &b, int pos) {
    if (pos >= (int)a.length())
        return true;

    for (int i = pos; i < (int)a.length(); i++) {
        if (a[i] == b[pos]) {
            swap(a[i], a[pos]);

            if (findPermutation(a, b, pos + 1))
                return true;
            else
                swap(a[i], a[pos]);

            break;
        }
    }

    int j = -1;
    for (int i = pos; i < (int)a.length(); i++) {
        if (a[i] < b[pos] && (j == -1 || a[i] > a[j])) {
            j = i;
        }
    }

    if (j == -1)
        return false;

    swap(a[pos], a[j]);

    sort(a.begin() + pos + 1, a.end());
    reverse(a.begin() + pos + 1, a.end());

    return true;
}

int main() {
    string a, b;
    cin >> a >> b;

    if (a.length() < b.length()) {
        sort(a.rbegin(), a.rend());
    } else {
        findPermutation(a, b, 0);
    }

    cout << a << '\n';

    return 0;
}
