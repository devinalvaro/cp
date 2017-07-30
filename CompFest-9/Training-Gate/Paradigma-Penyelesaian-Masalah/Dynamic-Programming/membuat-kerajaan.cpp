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

int main()
{
    ios_base::sync_with_stdio(0);

    long long r, c;
    cin >> r >> c;

    vector<vector<long long>> petak(r, vector<long long>(c));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> petak[i][j];

            if (i > 0)
                petak[i][j] += petak[i - 1][j];
            if (j > 0)
                petak[i][j] += petak[i][j - 1];
            if (i > 0 && j > 0)
                petak[i][j] -= petak[i - 1][j - 1];
        }
    }

    long long best_result = LLONG_MIN;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            for (int p = i; p < r; p++) {
                for (int q = j; q < c; q++) {
                    long long result = petak[p][q];

                    if (i > 0)
                        result -= petak[i - 1][q];
                    if (j > 0)
                        result -= petak[p][j - 1];
                    if (i > 0 && j > 0)
                        result += petak[i - 1][j - 1];

                    best_result
                        = max(best_result, result);
                }
            }
        }
    }

    cout << best_result << '\n';
}
