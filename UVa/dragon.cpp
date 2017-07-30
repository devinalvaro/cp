/* greedy : involving sorting */

#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int n, m, dragon[30000], knight[30000];
    cin >> n >> m;

    while (n != 0 && m != 0) {
        for (int i = 0; i < n; i++) {
            cin >> dragon[i];
        }

        for (int i = 0; i < m; i++) {
            cin >> knight[i];
        }

        sort(dragon, dragon + n);
        sort(knight, knight + m);
        int i = 0, j = 0, sum = 0;

        while (m >= n && i < n) {
            while (j < m && knight[j] < dragon[i]) {
                j++;
            }

            if (j == m) {
                break;
            } else {
                sum += knight[j];
                i++;
                j++;
            }
        }

        if (i == n) {
            cout << sum << '\n';
        } else {
            cout << "Loowater is doomed!\n";
        }

        cin >> n >> m;
    }
}
