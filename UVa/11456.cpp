/* dp : lis */

#include <climits>
#include <iostream>
#include <string.h>
using namespace std;

int n, arr[2000], arr_lis[2000], arr_lds[2000];

void process()
{
    arr_lis[n - 1] = 1;
    arr_lds[n - 1] = 1;

    for (int i = n - 2; i >= 0; i--) {
        int max_inc = 1, max_dec = 1;

        for (int j = i + 1; j < n; j++) {
            if (arr[i] < arr[j]) {
                max_inc = max(max_inc, 1 + arr_lis[j]);
            }

            if (arr[i] > arr[j]) {
                max_dec = max(max_dec, 1 + arr_lds[j]);
            }
        }

        arr_lis[i] = max_inc;
        arr_lds[i] = max_dec;
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--) {
        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        memset(arr_lis, 0, sizeof(arr_lis));
        memset(arr_lds, 0, sizeof(arr_lds));
        process();
        int result = 0;

        for (int i = 0; i < n; i++) {
            result = max(result, arr_lis[i] + arr_lds[i] - 1);
        }

        cout << result << '\n';
    }
}
