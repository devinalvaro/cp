#include <algorithm>
#include <bitset>
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

class Trie
{
private:
    vector<vector<int>> trie;
    vector<int> occurence;
    int last_index;

public:
    Trie()
    {
        trie.assign(300300, vector<int>(26, -1));
        occurence.assign(300300, 0);

        last_index = 25;
    }

    void insert(string word)
    {
        size_t index = word[0] - 'a';
        occurence[index]++;

        for (size_t i = 1; i < word.size(); i++) {
            int ascii = word[i] - 'a';

            if (trie[index][ascii] == -1) {
                trie[index][ascii] = ++last_index;
            }
            index = trie[index][ascii];

            occurence[index]++;
        }
    }

    int search(string word)
    {
        int index = word[0] - 'a';

        for (size_t i = 1; i < word.size(); i++) {
            int ascii = word[i] - 'a';

            if (trie[index][ascii] == -1) {
                return 0;
            }
            index = trie[index][ascii];
        }

        return occurence[index];
    }
};

int main()
{
    ios_base::sync_with_stdio(0);

    Trie trie;
    map<string, bool> dictionary;

    int n;
    cin >> n;

    while (n--) {
        int m;
        string s;
        cin >> m >> s;

        if (m == 1) {
            if (dictionary.find(s) == dictionary.end()) {
                dictionary[s] = true;

                trie.insert(s);
            }
        } else if (m == 2) {
            cout << trie.search(s) << '\n';
        }
    }
}
