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
        double n, m;
        cin >> n >> m;

        cout << fixed << setprecision(9) << m * m / n << '\n';
    }
}
