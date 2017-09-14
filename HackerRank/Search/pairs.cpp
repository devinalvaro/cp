#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++ ) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int numberOfPairs = 0;
    unordered_map<int, int> numCount;
    for (int i = 0; i < n; i++) {
        if (numCount.find(a[i]) == numCount.end()) {
            numCount[a[i]] = 1;
        } else {
            numCount[a[i]] += 1;
        }

        if (a[i] - k > 0 && numCount.find(a[i] - k) != numCount.end()) {
            numberOfPairs++;
        }
    }

    cout << numberOfPairs << '\n';
}
