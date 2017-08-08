/* number theory : lcd and gcm */

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

int gcd(int a, int b) {
    return (b == 0 ? a : gcd(b, a % b));
}

int main()
{
    ios_base::sync_with_stdio(0);

    vector<int> numbers(1000);
    while (cin >> numbers[0]) {
        if (numbers[0] == 0)
            break;

        int len = 1;
        while (cin >> numbers[len]) {
            if (numbers[len] == 0)
                break;

            len++;
        }

        int result = 0;
        for (int i = 1; i < len; i++) {
            numbers[i] -= numbers[0];

            result = gcd(result, numbers[i]);
        }

        cout << abs(result) << '\n';
    }
}

