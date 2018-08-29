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

void prime_divisors(int n, set<int> &divisors) {
    int s = sqrt(n);
    for (int i = 2; i <= s; i++) {
        if (n % i == 0) {
            divisors.insert(i);

            while (n % i == 0) {
                n /= i;
            }
        }
    }

    if (n > 1) {
        divisors.insert(n);
    }
}

int main() {
    int n;
    cin >> n;

    ve<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }

    set<int> divisors;
    prime_divisors(a[0], divisors);
    prime_divisors(b[0], divisors);

    for (auto it = divisors.begin(); it != divisors.end(); it++) {
        bool valid = true;

        for (int i = 1; i < n; i++) {
            if (a[i] % *it != 0 && b[i] % *it != 0) {
                valid = false;
                break;
            }
        }

        if (valid) {
            cout << *it << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}
