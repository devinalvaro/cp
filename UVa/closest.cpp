/* brute force : iterative */

#include <algorithm>
#include <climits>
#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int n, m, s, t, c = 1;
    cin >> n;

    while (n != 0) {
        cout << "Case " << c << ":\n";
        c++;
        int arr[n];

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        sort(arr, arr + n);
        t = INT_MAX;
        cin >> m;

        while (m--) {
            cin >> s;

            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    if (abs(s - (arr[i] + arr[j])) < abs(s - t)) {
                        t = arr[i] + arr[j];
                    }
                }
            }

            cout << "Closest sum to " << s << " is " << t << ".\n";
        }

        cin >> n;
    }
}
