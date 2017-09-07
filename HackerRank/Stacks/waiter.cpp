#include <bits/stdc++.h>

using namespace std;

/*
 * n: intended size of sieve [1...n]
 * is_prime: is_prime[i] means number i is prime
 */
void sieveOfEratosthenes(int n, bitset<1000000> &is_prime)
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
 * n: size of sieve [1...n]
 * is_prime: is_prime[i] means number i is prime
 * primes: resulting array of prime numbers from [1...n]
 */
void find_primes(int n, bitset<1000000> &is_prime, vector<int> &primes)
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

    int n, q;
    cin >> n >> q;

    bitset<1000000> is_prime;
    sieveOfEratosthenes(10000, is_prime);

    vector<int> primes;
    find_primes(10000, is_prime, primes);

    vector<pair<stack<int>, stack<int>>> table(q + 1);
    for (int i = 0; i < n; i++) {
        int number;
        cin >> number;

        table[0].first.push(number);
    }

    for (int i = 1; i <= q; i++) {
        while (!table[i - 1].first.empty()) {
            if (table[i - 1].first.top() % primes[i - 1] == 0) {
                table[i].second.push(table[i - 1].first.top());
            } else {
                table[i].first.push(table[i - 1].first.top());
            }
            table[i - 1].first.pop();
        }
    }

    for (int i = 1; i <= q; i++) {
        while (!table[i].second.empty()) {
            cout << table[i].second.top() << '\n';
            table[i].second.pop();
        }
    }
    while (!table[q].first.empty()) {
        cout << table[q].first.top() << '\n';
        table[q].first.pop();
    }
}
