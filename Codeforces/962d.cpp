#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    map<long long, priority_queue<int, vector<int>, greater<int>>> indices;

    long long a;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a);
        indices[a].push(i);
    }

    for (auto it = indices.begin(); it != indices.end(); it++) {
        while (it->second.size() >= 2) {
            it->second.pop();
            int j = it->second.top();
            it->second.pop();

            indices[2LL * it->first].push(j);
        }
    }

    vector<pair<int, long long>> arr;
    for (auto it = indices.begin(); it != indices.end(); it++) {
        while (!it->second.empty()) {
            arr.push_back(make_pair(it->second.top(), it->first));
            it->second.pop();
        }
    }

    sort(arr.begin(), arr.end());

    printf("%d\n%lld", (int)arr.size(), arr[0].second);
    for (int i = 1; i < (int)arr.size(); i++) {
        printf(" %lld", arr[i].second);
    }
    printf("\n");

    return 0;
}
