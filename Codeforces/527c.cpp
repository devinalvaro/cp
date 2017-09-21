#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);

    int w, h, n;
    cin >> w >> h >> n;

    map<int, int, greater<int>> verticalSegments, horizontalSegments;
    verticalSegments[h] = 1;
    horizontalSegments[w] = 1;

    set<int> verticalCuts, horizontalCuts;
    verticalCuts.insert(0);
    verticalCuts.insert(w);
    horizontalCuts.insert(0);
    horizontalCuts.insert(h);

    while (n--) {
        char type;
        int cut;

        cin >> type >> cut;

        if (type == 'V') {
            verticalCuts.insert(cut);

            auto iter = verticalCuts.find(cut);
            int hi = *(++iter);
            int low = *(--(--iter));

            horizontalSegments[hi - low]--;
            if (horizontalSegments[hi - low] == 0) {
                horizontalSegments.erase(hi - low);
            }

            horizontalSegments[hi - cut]++;
            horizontalSegments[cut - low]++;

        } else if (type == 'H') {
            horizontalCuts.insert(cut);

            auto iter = horizontalCuts.find(cut);
            int hi = *(++iter);
            int low = *(--(--iter));

            verticalSegments[hi - low]--;
            if (verticalSegments[hi - low] == 0) {
                verticalSegments.erase(hi - low);
            }

            verticalSegments[hi - cut]++;
            verticalSegments[cut - low]++;
        }

        cout << (long long)verticalSegments.begin()->first *
                    (long long)horizontalSegments.begin()->first
             << '\n';
    }
}
