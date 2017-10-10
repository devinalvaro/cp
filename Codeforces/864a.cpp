#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    set<int> numbers;
    map<int, int> numbers_count;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        numbers.insert(a);
        numbers_count[a]++;
    }

    if (numbers.size() != 2) {
        cout << "NO\n";
    } else {
        auto i = numbers.begin();
        auto j = numbers.begin(); ++j;

        if (numbers_count[*i] != numbers_count[*j]) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            cout << *i << ' ' << *j << '\n';
        }
    }
}
