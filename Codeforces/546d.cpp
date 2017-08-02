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

const int N = 5000000;

void sieve_of_eratosthenes(vector<int> &prime_divisor)
{
    for (int p = 2; p * p <= N; p++) {
        if (prime_divisor[p] == -1) {
            for (int i = p * 2; i <= N; i += p) {
                prime_divisor[i] = p;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);

    vector<int> prime_divisor(N + 1, -1);
    sieve_of_eratosthenes(prime_divisor);

    vector<int> prime_factor(N + 1, -1);
    for (int i = 1; i <= N; i++) {
        if (prime_divisor[i] == -1) {
            prime_factor[i] = 1;

            continue;
        }

        prime_factor[i] = prime_factor[i / prime_divisor[i]] + 1;
    }

    vector<int> prime_factor_sum(N + 1, 0);
    for (int i = 2; i <= N; i++) {
        prime_factor_sum[i] = prime_factor_sum[i - 1] + prime_factor[i];
    }

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int a, b;
        cin >> a >> b;

        cout << prime_factor_sum[a] - prime_factor_sum[b] << '\n';
    }
}
