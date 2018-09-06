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

/*
 * n: intended size of sieve [1...n]
 * is_prime: is_prime[i] means number i is prime
 */
void sieve_of_eratosthenes(int n, ve<bool> &is_prime)
{
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    ve<bool> is_prime(n + 10, true);
    sieve_of_eratosthenes(n, is_prime);

    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }

    for (int i = 1; i <= n; i++) {
        if (!is_prime[i]) {
            continue;
        }

        if (__gcd(i, sum - i) > 1) {
            printf("Yes\n");
            printf("1 %d\n", i);
            printf("%d", n - 1);
            for (int j = 1; j <= n; j++) {
                if (i == j) {
                    continue;
                }
                printf(" %d", j);
            }
            printf("\n");

            return 0;
        }
    }

    printf("No\n");

    return 0;
}
