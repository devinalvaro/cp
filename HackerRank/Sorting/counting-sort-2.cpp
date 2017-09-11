#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    unordered_map<int, int> numCount;

    vector<int> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];

        if (numCount.find(ar[i]) == numCount.end()) {
            numCount[ar[i]] = 1;
        } else {
            numCount[ar[i]] += 1;
        }
    }

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < numCount[i]; j++) {
            cout << i << ' ';
        }
    }
}
