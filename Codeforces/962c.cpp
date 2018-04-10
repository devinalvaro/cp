#include <bits/stdc++.h>

using namespace std;

int del_dist(const string &a, const string &b) {
    size_t i = 0, j = 0;

    int dist = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] == b[j]) {
            i++, j++;
            continue;
        }

        i++, dist++;
    }

    if (j < b.size())
        return INT_MAX;

    while (i < a.size()) {
        i++, dist++;
    }

    return dist;
}

int main() {
    string n;
    cin >> n;

    vector<string> squares;
    for (int i = 1; i * i <= 2e9; i++) {
        squares.push_back(to_string(i * i));
    }

    int result = INT_MAX;
    for (string square : squares) {
        result = min(result, del_dist(n, square));
    }

    if (result == INT_MAX) {
        printf("-1\n");
    } else {
        printf("%d\n", result);
    }

    return 0;
}
