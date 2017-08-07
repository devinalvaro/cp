/* dnc : binary search */

#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int n, m, p[20000];

    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }

        cin >> m;
        sort(p, p + n);
        int i = n / 2;
        cout << "Peter should buy books whose prices are ";

        for (int i = lower_bound(p, p + n, m / 2) - p; i < n; i++) {
            int pos = lower_bound(p, p + n, m - p[i]) - p;

            if (pos != i && p[pos] == m - p[i]) {
                cout << p[pos] << " and " << p[i] << ".\n\n";
                break;
            }
        }
    }
}
