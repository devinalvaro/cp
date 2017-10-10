#include <bits/stdc++.h>

using namespace std;

struct Item {
    int no;
    int t;
    int d;
    int p;

    bool operator<(const Item &that) {
        return d < that.d;
    }
};

int main() {
    int n;
    cin >> n;

    vector<Item> items(n);
    for (int i = 0; i < n; i++) {
        items[i].no = i + 1;
        cin >> items[i].t >> items[i].d >> items[i].p;
    }
    sort(items.begin(), items.end());

    int D = items[n - 1].d;

    vector<vector<int>> dp(n + 1, vector<int>(D, 0));
    vector<vector<pair<int, int>>> parent(
        n + 1, vector<pair<int, int>>(D, make_pair(0, 0)));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < D; j++) {
            int d = items[i - 1].d;
            int t = items[i - 1].t;
            int p = items[i - 1].p;

            dp[i][j] = dp[i - 1][j];
            parent[i][j] = make_pair(i - 1, j);

            if (j < d && j >= t && p + dp[i - 1][j - t] > dp[i][j]) {
                dp[i][j] = p + dp[i - 1][j - t];
                parent[i][j] = make_pair(i - 1, j - t);
            }
        }
    }

    int maxValue = INT_MIN, maxValueJ;
    for (int i = 0; i < D; i++) {
        if (dp[n][i] > maxValue) {
            maxValue = dp[n][i];
            maxValueJ = i;
        }
    }

    vector<int> savedItems;
    int i = n, j = maxValueJ;
    while (i != 0) {
        pair<int, int> temp = parent[i][j];

        if (temp.second != j) {
            savedItems.push_back(items[i - 1].no);
        }

        i = temp.first;
        j = temp.second;
    }

    cout << maxValue << '\n';
    cout << savedItems.size() << '\n';
    for (int i = savedItems.size() - 1; i >= 0; i--) {
        cout << savedItems[i] << (i == 0 ? '\n' : ' ');
    }
}
