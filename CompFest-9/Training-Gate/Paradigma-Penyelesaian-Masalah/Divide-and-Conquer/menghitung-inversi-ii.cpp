#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

long long merge(vector<long long> &a, vector<long long> &temp, int left,
                int mid, int right)
{
    long long inversion = 0;

    int i = left;
    int j = mid;
    int k = left;
    while ((i <= mid - 1) && (j <= right)) {
        if (a[i] <= a[j]) {
            temp[k++] = a[i++];
        } else {
            temp[k++] = a[j++];

            inversion += (mid - i);
        }
    }

    while (i <= mid - 1)
        temp[k++] = a[i++];

    while (j <= right)
        temp[k++] = a[j++];

    for (i = left; i <= right; i++)
        a[i] = temp[i];

    return inversion;
}

long long merge_sort(vector<long long> &a, vector<long long> &temp, int left,
                     int right)
{
    long long inversion = 0;

    if (right > left) {
        int mid = (right + left) / 2;

        inversion = merge_sort(a, temp, left, mid);
        inversion += merge_sort(a, temp, mid + 1, right);

        inversion += merge(a, temp, left, mid + 1, right);
    }

    return inversion;
}

int main()
{
    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<long long> temp(n);
    cout << merge_sort(a, temp, 0, n - 1) << '\n';
}
