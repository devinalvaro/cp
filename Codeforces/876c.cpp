#include <bits/stdc++.h>

using namespace std;

bool isEligible(int n, int x) {
    int y = x;

    while (x) {
        y += x % 10;
        x /= 10;
    }

    return (n == y);
}

int main() {
    int n;
    cin >> n;

    vector<int> variants;
    for (int i = n - 100; i <= n; i++) {
        if (isEligible(n, i)) {
            variants.push_back(i);
        }
    }

    cout << variants.size() << '\n';
    for (int i = 0; i < (int)variants.size(); i++) {
        cout << variants[i] << '\n';
    }
}
