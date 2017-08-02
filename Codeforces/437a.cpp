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

    string a, b, c, d;
    cin >> a >> b >> c >> d;

    int size_a = (int)a.size() - 2;
    int size_b = (int)b.size() - 2;
    int size_c = (int)c.size() - 2;
    int size_d = (int)d.size() - 2;

    int great = 0;
    char choice = 'C';

    if ((size_a <= size_b / 2 && size_a <= size_c / 2 &&
         size_a <= size_d / 2) ||
        (size_a >= size_b * 2 && size_a >= size_c * 2 &&
         size_a >= size_d * 2)) {
        great++;

        choice = 'A';
    }
    if ((size_b <= size_a / 2 && size_b <= size_c / 2 &&
         size_b <= size_d / 2) ||
        (size_b >= size_a * 2 && size_b >= size_c * 2 &&
         size_b >= size_d * 2)) {
        great++;

        choice = 'B';
    }
    if ((size_c <= size_b / 2 && size_c <= size_a / 2 &&
         size_c <= size_d / 2) ||
        (size_c >= size_b * 2 && size_c >= size_a * 2 &&
         size_c >= size_d * 2)) {
        great++;

        choice = 'C';
    }
    if ((size_d <= size_b / 2 && size_d <= size_c / 2 &&
         size_d <= size_a / 2) ||
        (size_d >= size_a * 2 && size_d >= size_c * 2 &&
         size_d >= size_a * 2)) {
        {
            great++;

            choice = 'D';
        }
    }

    if (great > 1) {
        choice = 'C';
    }

    cout << choice << '\n';
}
