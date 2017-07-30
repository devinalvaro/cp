/* dp : lis */

#include <iostream>
using namespace std;

int a[1000000], ans[1000000], ans_pos[1000000], p[1000000];
/* a: array berisi semua input
 * ans: array LIS
 * ans_pos: array berisi index posisi elemen-elemen ans di a
 * p : array yang mengubah indeks pada a menjadi indeks sebelumnya di
 * ans
 */

void print(int i)
{
    if (i >= 0) {
        print(p[i]);
        cout << a[i] << '\n';
    }
}

int main()
{
    int n, i = 0, len = 0, last = 0;

    while (cin >> n) {
        a[i] = n; // melakukan input
        int pos = lower_bound(ans, ans + len,
                      a[i])
            - ans; // mencari posisi yang tepat di ans untuk input baru
        ans[pos] = a[i];
        ans_pos[pos] = i;
        p[i] = pos > 0 ? ans_pos[pos - 1] : -1;

        if (pos == len) {
            len++;
            last = i;
        }

        i++; // indeks a selanjutnya
    }

    cout << len << "\n-\n";
    print(last);
}
