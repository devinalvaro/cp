#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        double n, p;
        cin >> n >> p;

        cout << fixed << setprecision(9) << (p / 100) * (pow(2, n) - 1) << '\n';
    }
}
