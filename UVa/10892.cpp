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

int gcd(int a, int b) { return (b == 0 ? a : gcd(b, a % b)); }

int lcm(int a, int b) { return (a * (b / gcd(a, b))); }

int main()
{
    ios_base::sync_with_stdio(0);

    int n;
    while (cin >> n) {
        if (n == 0)
            break;
        if (n == 1) {
            cout << "1 1\n";

            continue;
        }

        vector<int> factors;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                factors.push_back(i);
                if (n / i != i) {
                    factors.push_back(n / i);
                }
            }
        }

        int cardinality = 0;
        for (size_t i = 0; i < factors.size(); i++) {
            for (size_t j = i + 1; j < factors.size(); j++) {
                if (lcm(factors[i], factors[j]) == n) {
                    cardinality++;
                }
            }
        }

        cout << n << ' ' << cardinality + 1 << '\n';
    }
}
