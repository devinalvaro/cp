#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

const int N = 10001000;

void sieve_of_eratosthenes(vector<bool> &is_prime) {
    for (int p = 2; p * p <= N; p++) {
        if (is_prime[p]) {
            for (int i = p * 2; i <= N; i += p) {
                is_prime[i] = false;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);

    vector<bool> is_prime(N + 1, true);
    sieve_of_eratosthenes(is_prime);
    is_prime[0] = false;

    vector<int> primes;
    for (int i = 2; i <= N; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }

    int n;
    while (cin >> n) {
        if (n < 8) {
            cout << "Impossible.\n";

            continue;
        }

        if (n & 1) {
            cout << "2 3 ";

            n -= 5;
        } else {
            cout << "2 2 ";

            n -= 4;
        }
        for (size_t i = 0; i < primes.size() && n - primes[i] >= 0; i++) {
            if (n - primes[i] < 0) {
                cout << "Impossible.\n";

                break;
            }

            if (is_prime[n - primes[i]]) {
                cout << primes[i] << ' ' << n - primes[i] << '\n';

                break;
            }
        }
    }
}
