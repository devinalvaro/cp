#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    long long n, a;
    cin >> n >> a;

    vector<int> ballot(10);
    while (a > 0) {
        if (a == 1) {
            a /= 10;
            continue;
        }

        for (int i = 2; i <= a % 10; i++) {
            ballot[i]++;
        }

        a /= 10;
    }

    vector<int> primes = {2, 3, 5, 7};
    vector<int> non_primes = {4, 6, 8, 9};

    vector<int> result;

    for (int i = (int)primes.size() - 1; i >= 0; i--) {
        while (ballot[primes[i]] > 0) {
            result.push_back(primes[i]);

            for (int j = primes[i]; j >= 2; j--) {
                ballot[j]--;
            }
        }
    }

    for (int i = (int)non_primes.size() - 1; i >= 0; i--) {
        while (ballot[non_primes[i]] > 0) {
            ballot[non_primes[i]]--;

            if (non_primes[i] == 9) {
                ballot[3] += 2;
            } else if (non_primes[i] == 8) {
                ballot[2] += 3;
            } else if (non_primes[i] == 6) {
                ballot[2]++;
                ballot[3]++;
            } else {
                ballot[2] += 2;
            }
        }
    }

    for (int i = (int)primes.size() - 1; i >= 0; i--) {
        while (ballot[primes[i]] > 0) {
            result.push_back(primes[i]);

            for (int j = primes[i]; j >= 2; j--) {
                ballot[j]--;
            }
        }
    }

    sort(result.begin(), result.end(), greater<int>());

    for (int i = 0; i < (int)result.size(); i++) {
        cout << result[i];
    }
    cout << endl;
}
