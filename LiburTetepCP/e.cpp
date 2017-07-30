#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

bool isTransformable(string a, string b)
{
    if (a.length() != b.length())
        return false;

    int diff = 0;
    for (int i = 0; i < (int)a.length(); i++) {
        if (a[i] != b[i])
            diff++;

        if (diff > 1)
            break;
    }

    return diff == 1;
}

int main()
{
    int t;
    string w, l, start, end;
    map<string, int> dist;
    map<string, vector<string>> adj;

    cin >> t;
    while (t--) {
        adj.clear();

        vector<string> dict;
        while (true) {
            cin >> w;
            if (w == "*")
                break;

            dict.push_back(w);
        }
        for (int i = 0; i < (int)dict.size(); i++) {
            for (int j = 0; j < (int)dict.size(); j++) {
                if (i != j && isTransformable(dict[i], dict[j])) {
                    adj[dict[i]].push_back(dict[j]);
                }
            }
        }

        getline(cin, l);
        while (l.length() == 0) {
            getline(cin, l);
        }
        while (l.length() != 0) {
            start = l.substr(0, l.find(" "));
            end = l.substr(l.find(" ") + 1, l.length());

            dist.clear();
            dist[start] = 0;

            queue<string> q;
            q.push(start);

            while (!q.empty()) {
                string u = q.front();
                q.pop();

                for (int j = 0; j < (int)adj[u].size(); j++) {
                    string v = adj[u][j];
                    if (dist.find(v) == dist.end()) {
                        dist[v] = dist[u] + 1;
                        q.push(v);
                    }
                }
            }

            cout << start << ' ' << end << ' ' << dist[end] << endl;

            getline(cin, l);
        }

        if (t != 0)
            cout << endl;
    }
}
