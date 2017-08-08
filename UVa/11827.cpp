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
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b) { return (b == 0 ? a : gcd(b, a % b)); }

int main()
{
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    while (n--) {
        cin >> ws;

        string line;
        getline(cin, line);

        istringstream iss(line);
        int number;
        vector<int> numbers;
        while (iss >> number) {
            numbers.push_back(number);
        }

        int result = 0;
        for (size_t i = 0; i < numbers.size(); i++) {
            for (size_t j = i + 1; j < numbers.size(); j++) {
                result = max(result, gcd(numbers[i], numbers[j]));
            }
        }

        cout << result << '\n';
    }
}
