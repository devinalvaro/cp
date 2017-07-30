/* brute force : recursive backtracking */

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int a, b, n, m;
map<int, vector<int>> doms;

bool backtrack(int i, int x, map<int, vector<int>> doms)
{
    if (i == n && x == b) {
        return true;
    } else if (i >= n && x != b) {
        return false;
    }

    bool truth = false;

    for (vector<int>::iterator it = doms[x].begin(); it != doms[x].end();
         it++) {
        map<int, vector<int>> newDoms = doms;
        vector<int>::iterator pos
            = find(newDoms[x].begin(), newDoms[x].end(), *it);

        if (pos != newDoms[x].end()) {
            newDoms[x].erase(pos);
        }

        if (*it != x) {
            pos = find(newDoms[*it].begin(), newDoms[*it].end(), x);

            if (pos != newDoms[*it].end()) {
                newDoms[*it].erase(pos);
            }
        }

        truth = truth || backtrack(i + 1, *it, newDoms);
    }

    return truth;
}

int main()
{
    int x, y;
    cin >> n;

    while (n != 0) {
        doms.clear();
        cin >> m;
        cin >> x >> a;
        cin >> b >> x;

        for (int i = 0; i < m; i++) {
            cin >> x >> y;
            doms[x].push_back(y);

            if (x != y) {
                doms[y].push_back(x);
            }
        }

        if (backtrack(0, a, doms)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }

        cin >> n;
    }
}
