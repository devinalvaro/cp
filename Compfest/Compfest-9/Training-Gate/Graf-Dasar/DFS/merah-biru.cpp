#include <algorithm>
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

int main()
{
    ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    map<int, vector<int>> edges;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        edges[a - 1].push_back(b - 1);
        edges[b - 1].push_back(a - 1);
    }

    vector<char> color(n, 'u');
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (color[i] == 'u') {
            q.push(i);
            color[0] = 'm';
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int j = 0; j < (int)edges[u].size(); j++) {
                int v = edges[u][j];

                if (color[v] == 'u') {
                    color[v] = (color[u] == 'm' ? 'b' : 'm');

                    q.push(v);
                } else if (color[v] == color[u]) {
                    cout << "TIDAK\n";

                    return 0;
                }
            }
        }
    }

    cout << "YA\n";
}
