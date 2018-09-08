#include <bits/stdc++.h>

using namespace std;

int root = -1;

vector<string> words;
unordered_map<string, int> dictionary;
unordered_map<int, vector<int>> children;
vector<vector<int>> dp;

int numberOfPairs(int node, bool take) {
    if (children[node].size() == 0)
        return dp[node][0] = dp[node][1] = 0;

    if (dp[node][1] == -1) {
        dp[node][1] = 0;

        for (int child : children[node]) {
            dp[node][1] += numberOfPairs(child, false);
        }
    }

    int childrenSum = dp[node][1];

    if (dp[node][0] == -1) {
        dp[node][0] = 0;

        for (int child : children[node]) {
            dp[node][0] =
                max(dp[node][0], 1 + childrenSum - numberOfPairs(child, false) +
                                     numberOfPairs(child, true));
        }
    }

    return (take ? dp[node][1] : dp[node][0]);
}

int numberOfPairs(int root) {
    int result = 0;
    for (int node : children[root]) {
        result += max(numberOfPairs(node, true), numberOfPairs(node, false));
    }

    return result;
}

int main() {
    int tc;
    cin >> tc;

    for (int tn = 1; tn <= tc; tn++) {
        cout << "Case #" << tn << ": ";

        int n;
        cin >> n;

        words.assign(n, "");
        dictionary.clear();
        children.clear();
        dp.assign(n, vector<int>(2, -1));

        for (int i = 0; i < n; i++) {
            cin >> words[i];
            dictionary[words[i]] = i;
        }

        for (int i = 0; i < n; i++) {
            string parent = words[i].substr(0, words[i].size() - 1);
            if (dictionary.find(parent) != dictionary.end()) {
                children[dictionary[parent]].push_back(i);
            } else {
                children[root].push_back(i);
            }
        }

        cout << numberOfPairs(root) << '\n';
    }
}
