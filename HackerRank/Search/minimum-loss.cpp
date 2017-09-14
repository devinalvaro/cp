#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    vector<long long> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    long long minLoss = LLONG_MAX;
    long long maxPrice = p[0];

    set<long long> bst;
    bst.insert(p[0]);

    for (int i = 1; i < n; i++) {
        if (p[i] < maxPrice) {
            minLoss = min(minLoss, *bst.upper_bound(p[i]) - p[i]);
        }

        bst.insert(p[i]);
        maxPrice = max(maxPrice, p[i]);
    }

    cout << minLoss << '\n';
}
