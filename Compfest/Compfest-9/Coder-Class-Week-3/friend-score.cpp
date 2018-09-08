#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class UFDS
{
private:
    vector<int> parent;
    vector<int> level;
    vector<int> score;

public:
    int find(int u) { return (parent[u] == u ? u : find(parent[u])); }

    void merge(int u, int v, vector<set<pair<int, int>>> &pending_friends)
    {
        int au = find(u);
        int av = find(v);
        int ax;

        if (au == av) {
            return;
        }

        if (level[au] > level[av]) {
            parent[av] = au;

            ax = au;
        } else {
            parent[au] = av;

            ax = av;

            if (level[au] == level[av]) {
                level[av]++;
            }
        }

        score[ax] += score[(ax == au ? av : au)];
        score[(ax == au ? av : au)] = 0;

        if (pending_friends[au].size() > pending_friends[av].size()) {
            int temp = au;
            au = av;
            av = temp;
        }

        for (auto i = pending_friends[au].begin();
             i != pending_friends[au].end();) {
            auto j = pending_friends[av].find(*i);
            if (j != pending_friends[av].end()) {
                pending_friends[av].erase(j);
                pending_friends[au].erase(i++);

                score[ax]++;
            } else {
                i++;
            }
        }

        for (auto i = pending_friends[au].begin();
             i != pending_friends[au].end(); i++) {
            pending_friends[av].insert(*i);
        }

        pending_friends[ax] = pending_friends[av];
    }

    int get_score(int u) { return score[find(u)]; }

    UFDS(int n)
    {
        parent.assign(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }

        level.assign(n + 1, 1);

        score.assign(n + 1, 0);
    }
};

int main()
{
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m, q;
        cin >> n >> m >> q;

        vector<set<pair<int, int>>> pending_friends(n + 1);

        while (m--) {
            int u, v;
            cin >> u >> v;

            pending_friends[u].insert(make_pair(min(u, v), max(u, v)));
            pending_friends[v].insert(make_pair(min(u, v), max(u, v)));
        }

        UFDS companies(n);

        while (q--) {
            int p, a, b, c;
            cin >> p;

            if (p == 1) {
                cin >> a >> b;

                companies.merge(a, b, pending_friends);
            } else if (p == 2) {
                cin >> c;

                cout << companies.get_score(c) << '\n';
            }
        }
    }
}
