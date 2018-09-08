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

    int n, m;
    cin >> n >> m;

    vector<int> degree(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        degree[u - 1]++;
        degree[v - 1]++;
    }

    int odd_degree = 0;
    for (int i = 0; i < n; i++) {
        if (degree[i] & 1) {
            odd_degree++;
        }
    }

    if (odd_degree == 0) {
        cout << "Tipe A\n";
    } else if (odd_degree == 2) {
        cout << "Tipe B\n";
    } else {
        cout << "Tipe C\n";
    }
}
