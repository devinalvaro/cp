#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ll long long
#define ve vector

map<int, ve<int>> edges;
bool visited[100001];
set<int> enders;

void dfs(int u) {
    if (visited[u]) {
        return;
    }

    visited[u] = true;

    set<int> children;
    for (int v : edges[u]) {
        if (!visited[v]) {
            children.insert(v);
        }
    }

    if (children.size() > 1) {
        return;
    } else if (children.size() == 1) {
        dfs(*children.begin());
    } else {
        enders.insert(u);
    }
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    int e, ne = 0;
    for (int i = 1; i <= n; i++) {
        if ((int)edges[i].size() > ne) {
            ne = edges[i].size();
            e = i;
        }
    }

    visited[e] = true;
    for (int v : edges[e]) {
        if (!visited[v]) {
            dfs(v);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            cout << "No\n";
            return 0;
        }
    }

    cout << "Yes\n";
    cout << enders.size() << endl;
    for (auto it = enders.begin(); it != enders.end(); it++) {
        cout << e << " " << *it << endl;
    }

    return 0;
}
