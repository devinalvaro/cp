#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    long long b, s, d;
    cin >> b >> s >> d;

    long long best_result = LLONG_MAX;

    // 0 = breakfast, 1 = supper, 2 = dinner
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            long long B = b, S = s, D = d;

            if (i == 0)
                B--;
            if (i <= 1)
                S--;
            if (i <= 2)
                D--;

            if (j >= 0)
                B--;
            if (j >= 1)
                S--;
            if (j == 2)
                D--;

            long long M = max(B, max(S, D));
            long long local_result = (M - B) + (M - S) + (M - D);

            best_result = min(best_result, local_result);

            /* cout << (i == 0 ? 'B' : i == 1 ? 'S' : 'D') << ' '; */
            /* cout << (j == 0 ? 'B' : j == 1 ? 'S' : 'D') << endl; */
            /* cout << B << ' ' << S << ' ' << D << endl; */
            /* cout << M << ' ' << local_result << endl; */
            /* cout << endl; */
        }
    }

    cout << best_result << endl;
}
