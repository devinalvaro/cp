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

    int n;
    cin >> n;

    int solusi = 0;
    for (int a = 0; a <= n; a++) {
        for (int b = 0; b <= n; b++) {
            for (int c = 0; c <= n; c++) {
                if (a + b + c == n) {
                    solusi++;
                }
            }
        }
    }

    cout << solusi << '\n';
}
