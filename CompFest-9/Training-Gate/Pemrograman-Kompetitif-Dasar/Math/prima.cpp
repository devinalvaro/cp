#include <algorithm>
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

const int N = 1000000;

vector<bool> sieve(N + 1, true);
vector<int> primes;

void sieve_of_eratosthenes()
{
    for (int i = 2; i * i <= N; i++) {
        if (sieve[i]) {
            for (int j = 2 * i; j <= N; j += i) {
                sieve[j] = false;
            }
        }
    }

    for (int i = 2; i <= N; i++) {
        if (sieve[i]) {
            primes.push_back(i);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);

    sieve_of_eratosthenes();

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cout << primes[(i * k)] << '\n';
    }
}
