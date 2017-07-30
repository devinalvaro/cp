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

    int n, q;
    cin >> n >> q;

    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;

        if (*lower_bound(b.begin(), b.end(), x) == x) {
            cout << "ada\n";
        } else {
            cout << "tidak ada\n";
        }
    }
}
