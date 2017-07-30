/* brute force : recursive backtracking */

#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int t, tr[100], songs, unused;
vector<int> ans, curAns;

void backtrack(int i, int remN, int j, vector<int> curAns)
{
    if (remN < unused && remN >= 0) {
        ans = curAns;
        songs = j;
        unused = remN;
    } else if (remN == unused && remN >= 0 && j > songs) {
        ans = curAns;
        songs = j;
        unused = remN;
    }

    if (i >= t || remN <= 0) {
        return;
    }

    vector<int> newAns = curAns;
    newAns.push_back(tr[i]);
    backtrack(i + 1, remN - tr[i], j + 1, newAns);
    backtrack(i + 1, remN, j, curAns);
}

int main()
{
    int n;

    while (cin >> n) {
        cin >> t;

        for (int i = 0; i < t; i++) {
            cin >> tr[i];
        }

        ans.clear();
        curAns.clear();
        songs = INT_MIN;
        unused = INT_MAX;
        backtrack(0, n, 0, curAns);
        int sum = 0;

        for (vector<int>::iterator i = ans.begin(); i != ans.end(); i++) {
            cout << *i << ' ';
            sum += *i;
        }

        cout << "sum:" << sum << '\n';
    }
}
