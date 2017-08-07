/* greedy : non classical */

#include <iostream>
using namespace std;

int main()
{
    int n, t, sum, arr[2000];
    cin >> n;

    while (n != 0) {
        sum = 0;
        int j = 0;

        for (int i = 0; i < n; i++) {
            cin >> t;
            sum += t;

            if (t != 0) {
                arr[j] = t;
                j++;
            }
        }

        if (sum == 0) {
            cout << '0';
        } else {
            for (int i = 0; i < j; i++) {
                cout << arr[i];

                if (i != j - 1) {
                    cout << ' ';
                }
            }
        }

        cout << '\n';
        cin >> n;
    }
}
