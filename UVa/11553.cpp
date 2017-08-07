/* brute force : iterative */

#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int factorial(int n)
{
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main()
{
    int n;
    cin >> n;

    while (n--) {
        int t, x;
        cin >> t;
        vector<vector<int>> M(t, vector<int>(t));

        for (int i = 0; i < t; i++) {
            for (int j = 0; j < t; j++) {
                cin >> x;
                M[i][j] = x;
            }
        }

        sort(M.begin(), M.end());
        int hi = INT_MAX;

        do {
            int temp = 0;

            for (int i = 0; i < t; i++) {
                temp += M[i][i];
            }

            hi = min(temp, hi);
        } while (next_permutation(M.begin(), M.end()));

        cout << hi << '\n';
    }
}
