#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k, m;
    cin >> n >> k >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    map<int, vector<int>> number_count;
    for (int i = 0; i < n; i++) {
        number_count[a[i] % m].push_back(a[i]);
    }

    for (auto it : number_count) {
        if ((int)it.second.size() >= k) {
            cout << "Yes\n";

            for (int i = 0; i < k; i++) {
                cout << it.second[i] << (i == k - 1 ? '\n' : ' ');
            }

            return 0;
        }
    }

    cout << "No\n";
}
