#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k, m;
    scanf("%d %d %d", &n, &k, &m);

    map<string, int> words;
    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;
        words[word] = i;
    }
    vector<long long> cost(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &cost[i]);
    }

    vector<int> nums;
    for (int i = 0; i < k; i++) {
        int x;
        scanf("%d", &x);

        long long min_cost = LLONG_MAX;
        for (int j = 0; j < x; j++) {
            int k;
            scanf("%d", &k);
            nums.push_back(k - 1);

            min_cost = min(min_cost, cost[k - 1]);
        }

        for (int j = 0; j < x; j++) {
            cost[nums[j]] = min_cost;
        }

        nums.clear();
    }

    long long sum = 0;
    for (int i = 0; i < m; i++) {
        string word;
        cin >> word;

        sum += cost[words[word]];
    }

    printf("%lld\n", sum);

    return 0;
}
