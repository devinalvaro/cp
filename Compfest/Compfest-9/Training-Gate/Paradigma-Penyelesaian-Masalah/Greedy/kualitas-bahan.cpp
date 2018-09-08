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

    long long n;
    cin >> n;

    long long gizi = 0;
    vector<long long> makanan(n);
    for (long long i = 0; i < n; i++) {
        cin >> makanan[i];
        gizi += makanan[i];
    }
    for (long long i = 0; i < n; i++) {
        cin >> makanan[i];
    }

    sort(makanan.rbegin(), makanan.rend());

    for (long long i = 0; i < n; i++) {
        gizi -= i * makanan[i];
    }

    cout << gizi << '\n';
}
