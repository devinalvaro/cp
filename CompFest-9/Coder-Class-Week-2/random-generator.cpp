#include <algorithm>
#include <bitset>
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

    int t;
    cin >> t;

    vector<vector<int>> pascal_triangle(51, vector<int>(51));
    pascal_triangle[0][0] = 1;
    for (int i = 1; i <= 50; i++) {
        pascal_triangle[i][0] = 1;
        for (int j = 1; j <= i - 1; j++) {
            pascal_triangle[i][j] =
                pascal_triangle[i - 1][j] + pascal_triangle[i - 1][j - 1];
        }
        pascal_triangle[i][i] = 1;
    }

    while (t--) {
        int n;
        double p;
        cin >> n >> p;
        p /= 100;
    }
}
