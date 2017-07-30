#include <algorithm>
#include <bitset>
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

bool is_antiarithmetic(int n, const vector<int> &a, const vector<int> &index) {
    for (int i = 1; i <= n; i++) {
        for (int d = 1; d <= n / 2; d++) {
            if (a[i] - d < 0 || a[i] + d >= n) {
                break;
            }

            if (index[a[i] - d] < index[a[i]] && index[a[i] + d] > index[a[i]]) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(0);

    string s;
    while (cin >> s) {
        if (s == "0")
            break;

        int n = stoi(s.substr(0, s.size() - 1));
        vector<int> a(n), index(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            index[a[i]] = i;
        }

        if (is_antiarithmetic(n, a, index)) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }
}
