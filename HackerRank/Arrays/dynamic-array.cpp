#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);

    int n, q;
    cin >> n >> q;

    vector<vector<int>> seqList(n);
    int lastAnswer = 0;

    while (q--) {
        int c, x, y;
        cin >> c >> x >> y;

        int i = (x ^ lastAnswer) % n;

        if (c == 1) {
            seqList[i].push_back(y);
        } else if (c == 2) {
            lastAnswer = seqList[i][y % seqList[i].size()];
            cout << lastAnswer << '\n';
        }
    }
}
