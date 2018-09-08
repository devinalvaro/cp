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

    vector<pair<int, int>> komik(n);
    for (int i = 0; i < n; i++) {
        cin >> komik[i].first;
        komik[i].second = i;
    }

    sort(komik.begin(), komik.end());

    int swaps = 0;
    vector<bool> visited(n);
    for (int i = 0; i < n; i++) {
        if (visited[i] || komik[i].second == i)
            continue;

        int j = i, cycle_size = 0;
        while (!visited[j]) {
            visited[j] = true;

            j = komik[j].second;
            cycle_size++;
        }

        swaps += (cycle_size - 1);
    }

    cout << swaps << '\n';
}
