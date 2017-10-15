#include <bits/stdc++.h>

using namespace std;

vector<int> p, v;
map<int, vector<int>> children;
vector<vector<int>> dp;

// dp[node][true] = sum(dp[child][true])
// dp[node][false] = sum(min(dp[child][true], dp[child][false]))

int minAlteration(int node, int truth) {
    if (children[node].size() == 0)
        return dp[node][truth] = v[node] ^ truth;

    if (dp[node][1] == -1) {
        dp[node][1] = v[node] ^ 1;
        for (int child : children[node]) {
            dp[node][1] += minAlteration(child, 1);
        }
    }

    if (dp[node][0] == -1) {
        dp[node][0] = v[node] ^ 0;
        for (int child : children[node]) {
            dp[node][0] +=
                min(minAlteration(child, 1), minAlteration(child, 0));
        }
    }

    return (truth ? dp[node][1] : dp[node][0]);
}

int minAlteration(int node) {
    int result = 0;
    for (int child : children[node]) {
        result += min(minAlteration(child, 1), minAlteration(child, 0));
    }

    return result;
}

int main() {
    int tc;
    cin >> tc;

    for (int tn = 1; tn <= tc; tn++) {
        cout << "Case #" << tn << ": ";

        children.clear();

        int n;
        cin >> n;

        p.assign(n, 0);
        v.assign(n, 0);
        dp.assign(n, vector<int>(2, -1));

        for (int i = 0; i < n; i++) {
            cin >> p[i];
            children[p[i] - 1].push_back(i);
        }
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }

        cout << minAlteration(-1) << '\n';
    }
}
