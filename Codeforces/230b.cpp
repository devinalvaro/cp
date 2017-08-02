#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

vector<long long> primes;

void sievePrimes()
{
    long long n = 1000001;
    vector<bool> prime(n, true);

    for (long long p = 2; p * p <= n; p++) {
        if (prime[p]) {
            for (long long i = p * 2; i <= n; i += p) {
                prime[i] = false;
            }
        }
    }

    for (long long p = 2; p <= n; p++) {
        if (prime[p])
            primes.push_back(p * p);
    }
}

int main()
{
    sievePrimes();

    long long n;
    cin >> n;

    long long p;
    for (long long i = 0; i < n; i++) {
        cin >> p;
        if (p == 1) {
            cout << "NO" << endl;
            continue;
        }

        vector<long long>::iterator j =
            lower_bound(primes.begin(), primes.end(), p);
        if (*j == p) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
