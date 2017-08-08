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
void sieve_of_eratosthenes(int n, bitset<50050> &is_prime)
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
void find_primes(int n, bitset<50050> &is_prime,
                 vector<unsigned int> &primes)
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

    bitset<50050> is_prime;
    sieve_of_eratosthenes(50000, is_prime);

    vector<unsigned int> primes;
    find_primes(48000, is_prime, primes);

    unsigned int l, r;
    while (cin >> l >> r) {
        vector<unsigned int> primes1;

        if (r <= 50000) {
            for (auto prime = lower_bound(primes.begin(), primes.end(), l);
                 prime != primes.end() && *prime <= r; prime++) {
                primes1.push_back(*prime);
            }
        } else {
            bitset<1000010> is_prime1;
            is_prime1.set();

            for (size_t i = 0; i < primes.size() && primes[i] * primes[i] <= r;
                 i++) {
                if (primes[i] * primes[i] > r)
                    break;

                unsigned int p = primes[i];
                unsigned int start;

                for (unsigned int j = (p * p > l ? p * p : l); j <= r; j++) {
                    if (j != p && j % p == 0) {
                        start = j;

                        break;
                    }
                }

                for (unsigned int j = start; j <= r; j += p) {
                    is_prime1[j - l] = 0;
                }
            }

            for (unsigned int j = l; j <= r; j++) {
                if (is_prime1[j - l]) {
                    primes1.push_back(j);
                }
            }
        }

        if (primes1.size() <= 1) {
            cout << "There are no adjacent primes.\n";

            continue;
        }

        pair<unsigned int, unsigned int> furthest_pair, nearest_pair;
        furthest_pair = make_pair(primes1[0], primes1[1]);
        nearest_pair = make_pair(primes1[0], primes1[1]);

        unsigned int furthest = primes1[1] - primes1[0];
        unsigned int nearest = primes1[1] - primes1[0];

        for (size_t i = 0; i < primes1.size() - 1; i++) {
            if (primes1[i + 1] - primes1[i] > furthest) {
                furthest = primes1[i + 1] - primes1[i];

                furthest_pair.first = primes1[i];
                furthest_pair.second = primes1[i + 1];
            }

            if (primes1[i + 1] - primes1[i] < nearest) {
                nearest = primes1[i + 1] - primes1[i];

                nearest_pair.first = primes1[i];
                nearest_pair.second = primes1[i + 1];
            }
        }

        cout << nearest_pair.first << ',' << nearest_pair.second
             << " are closest, ";
        cout << furthest_pair.first << ',' << furthest_pair.second
             << " are most distant.\n";
    }
}
