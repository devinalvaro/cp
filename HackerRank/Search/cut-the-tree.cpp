#include <bits/stdc++.h>

using namespace std;

int findSum(vector<int> &data, map<int, vector<int>> &adjacent, int u,
            vector<bool> &visited, vector<int> &sum)
{
    visited[u] = true;

    sum[u] += data[u];

    for (int j = 0; j < (int)adjacent[u].size(); j++) {
        int v = adjacent[u][j];

        if (!visited[v]) {
            sum[u] += findSum(data, adjacent, v, visited, sum);
        }
    }

    return sum[u];
}

int main()
{
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    vector<int> data(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }

    map<int, vector<int>> adjacent;
    vector<pair<int, int>> edges;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;

        adjacent[u - 1].push_back(v - 1);
        adjacent[v - 1].push_back(u - 1);

        edges.push_back(make_pair(u - 1, v - 1));
    }

    vector<int> sum(n, 0);
    vector<bool> visited(n, false);
    findSum(data, adjacent, 0, visited, sum);

    int minDiff = INT_MAX;

    for (int i = 0; i < (int)edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;

        minDiff = min(
            minDiff, abs((sum[0] - min(sum[u], sum[v])) - min(sum[u], sum[v])));
    }

    cout << minDiff << '\n';
}
