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
 * n: unsigned intended size of sieve [1...n]
 * is_prime: is_prime[i] means number i is prime
 */
void sieve_of_eratosthenes(int n, bitset<20000020> &is_prime)
{
    is_prime.set();
    is_prime[0] = is_prime[1] = 0;

    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = 0;
            }
        }
    }
}

/**
 * is_prime: is_prime[i] means number i is prime
 * primes: resulting array of prime numbers from [1...n]
 */
void find_primes(int n, bitset<20000020> &is_prime, vector<int> &primes)
{
    primes.clear();

    for (int i = 0; i <= n; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);

    bitset<20000020> is_prime;
    sieve_of_eratosthenes(18500000, is_prime);

    vector<int> primes;
    find_primes(18500000, is_prime, primes);

    vector<pair<int, int>> twin_primes;
    for (size_t i = 0; i < primes.size() - 1; i++) {
        if (primes[i + 1] - primes[i] == 2) {
            twin_primes.push_back(make_pair(primes[i], primes[i + 1]));
        }
    }

    int n;
    while (cin >> n) {
        cout << '(' << twin_primes[n - 1].first << ", " << twin_primes[n - 1].second << ")\n";
    }
}
