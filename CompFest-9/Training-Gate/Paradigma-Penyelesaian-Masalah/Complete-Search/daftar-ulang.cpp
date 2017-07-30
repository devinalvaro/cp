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

    vector<string> daftar(n);
    for (int i = 0; i < n; i++) {
        cin >> daftar[i];
    }

    vector<string> antri(q);
    for (int i = 0; i < q; i++) {
        string nama;
        cin >> nama;

        if (find(daftar.begin(), daftar.end(), nama) == daftar.end()) {
            cout << -1 << '\n';

            continue;
        }

        cout << find(daftar.begin(), daftar.end(), nama) - daftar.begin() + 1
             << '\n';
    }
}
