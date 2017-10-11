#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> x(n), y(n);
    unordered_set<int> numbers;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        numbers.insert(x[i]);
    }
    for (int i = 0; i < n; i++) {
        cin >> y[i];
        numbers.insert(y[i]);
    }

    int result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (numbers.find(x[i] ^ y[j]) != numbers.end()) {
                result++;
            }
        }
    }
    cout << (result & 1 ? "Koyomi" : "Karen") << '\n';
}
