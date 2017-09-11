#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    vector<int> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }

    int pivotIndex = 0;
    int pivot = ar[pivotIndex];

    int storeIndex = pivotIndex + 1;

    for (int i = pivotIndex + 1; i < n; i++) {
        if (ar[i] < pivot) {
            swap(ar[i], ar[storeIndex]);

            storeIndex++;
        }
    }

    swap(ar[pivotIndex], ar[storeIndex - 1]);

    for (int i = 0; i < n ; i++) {
        cout << ar[i] << (i == n - 1 ? '\n' : ' ');
    }
}
