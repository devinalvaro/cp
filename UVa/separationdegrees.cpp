/* graph : apsp (variant) */

#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

int main()
{
    int p, r, tc = 0;

    while (cin >> p >> r) {
        if (p == 0 && r == 0)
            break;

        string name;
        set<string> people;
        vector<string> relation;

        for (int i = 0; i < 2 * r; i++) {
            cin >> name;
            people.insert(name);
            relation.push_back(name);
        }

        int t = 0;
        map<string, int> id;

        for (set<string>::iterator it = people.begin(); it != people.end();
             it++) {
            id[*it] = t++;
        }

        vector<vector<int>> degree(p, vector<int>(p, 10e4));

        for (int i = 0; i < p; i++) {
            degree[i][i] = 0;
        }

        for (int i = 0; i < (int)relation.size(); i += 2) {
            degree[id[relation[i]]][id[relation[i + 1]]] = 1;
            degree[id[relation[i + 1]]][id[relation[i]]] = 1;
        }

        for (int k = 0; k < p; k++) {
            for (int i = 0; i < p; i++) {
                for (int j = 0; j < p; j++) {
                    degree[i][j]
                        = min(degree[i][j], degree[i][k] + degree[k][j]);
                }
            }
        }

        /* for (int i = 0; i < p; i++) { */
        /*   for (int j = 0; j < p; j++) { */
        /*     if (degree[i][j] >= 10e4) */
        /*       cout << "- "; */
        /*     else */
        /*       cout << degree[i][j] << ' '; */
        /*   } */

        /*   cout << '\n'; */
        /* } */

        int result = 0;

        for (int i = 0; i < p; i++) {
            for (int j = 0; j < p; j++) {
                result = max(result, degree[i][j]);
            }
        }

        cout << "Network " << ++tc << ": ";

        if (result >= 10e4) {
            cout << "DISCONNECTED\n";
        } else {
            cout << result << '\n';
        }

        cout << '\n';
    }
}
