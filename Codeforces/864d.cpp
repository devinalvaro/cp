#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    map<int, int> numbers;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        numbers[a[i]]++;
    }

    vector<int> leftNumbers;

    for (int i = 1; i <= n; i++) {
        if (numbers.find(i) == numbers.end()) {
            leftNumbers.push_back(i);
        }
    }

    sort(leftNumbers.begin(), leftNumbers.end());

    int j = 0, change = 0;
    map<int, bool> visited;

    for (int i = 0; i < n && j < (int)leftNumbers.size(); i++) {
        if (numbers[a[i]] > 1 && (leftNumbers[j] < a[i] || visited[a[i]])) {
            numbers[a[i]]--;
            a[i] = leftNumbers[j++];

            change++;
        }

        visited[a[i]] = true;
    }

    cout << change << '\n';
    for (int i = 0; i < n; i++) {
        cout << a[i] << (i == n - 1 ? '\n' : ' ');
    }
}
