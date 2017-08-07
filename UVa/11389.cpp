/* greedy : classical */

#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int n, d, r, day[1000], night[1000];
    cin >> n >> d >> r;

    while (n != 0 || d != 0 || r != 0) {
        for (int i = 0; i < n; i++) {
            cin >> day[i];
        }

        for (int i = 0; i < n; i++) {
            cin >> night[i];
        }

        sort(day, day + n);
        sort(night, night + n);
        int amount = 0;

        for (int i = 0; i < n; i++) {
            if (day[i] + night[n - 1 - i] > d) {
                amount += (day[i] + night[n - 1 - i] - d);
            }
        }

        cout << amount * r << '\n';
        cin >> n >> d >> r;
    }
}
