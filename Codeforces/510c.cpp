/* Fox and Names */

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> previous(26);
vector<bool> inpath(26), visited(26);
vector<char> sequence;

void topo_sort(int u) {
    if (visited[u])
        return;

    inpath[u] = true;
    visited[u] = true;

    for (int j = 0; j < (int)previous[u].size(); j++) {
        int v = previous[u][j];

        if (inpath[v]) {
            printf("Impossible\n");
            exit(0);
        }

        if (!visited[v]) {
            topo_sort(v);
        }
    }

    inpath[u] = false;
    sequence.push_back('a' + u);
}

int main() {
    int n;
    scanf("%d", &n);

    vector<string> names(n);
    for (int i = 0; i < n; i++) {
        cin >> names[i];
    }

    for (int i = 0; i < n - 1; i++) {
        bool diff = false;
        for (int j = 0; j < (int)min(names[i].size(), names[i + 1].size());
             j++) {
            int u = names[i][j] - 'a';
            int v = names[i + 1][j] - 'a';

            if (u != v) {
                previous[v].push_back(u);
                diff = true;
                break;
            }
        }

        if (!diff && names[i].size() > names[i + 1].size()) {
            printf("Impossible\n");
            return 0;
        }
    }

    for (int u = 0; u < 26; u++) {
        topo_sort(u);
    }

    for (int i = 0; i < 26; i++) {
        printf("%c", sequence[i]);
    }
    printf("\n");

    return 0;
}
