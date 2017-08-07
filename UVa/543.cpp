/* number theory : prime numbers */

#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;

/*
 * n: size of sieve [1...n]
 * is_prime: is_prime[i] means number i is prime
 */
void sieve_of_eratosthenes(int n, vector<bool> &is_prime)
{
    is_prime.assign(n + 1, true);

    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

/**
 * is_prime: is_prime[i] means number i is prime
 * primes: resulting array of prime numbers from [1...n]
 */
void find_primes(vector<bool> &is_prime, vector<int> &primes)
{
    for (size_t i = 0; i < is_prime.size(); i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);

    vector<bool> is_prime;
    sieve_of_eratosthenes(1000000, is_prime);

    vector<int> primes;
    find_primes(is_prime, primes);

    int n;
    while (cin >> n) {
        if (n == 0)
            break;

        for (size_t i = 0; i < primes.size() && primes[i] <= n; i++) {
            if (is_prime[n - primes[i]]) {
                cout << n << " = " << primes[i] << " + " << n - primes[i]
                     << '\n';

                break;
            }
        }
    }
}
