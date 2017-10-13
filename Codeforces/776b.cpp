#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    int k = 1;
    vector<int> sieve(n + 2, 1);
    for (int i = 2; i <= n + 1; i++) {
        if (sieve[i] == 1) {
            for (int j = i * 2; j <= n + 1; j += i) {
                sieve[j] = sieve[i] + 1;

                k = max(k, sieve[j]);
            }
        }
    }

    cout << k << '\n';
    for (int i = 2; i <= n + 1; i++) {
        cout << sieve[i] << (i == n + 1 ? '\n' : ' ');
    }
}
