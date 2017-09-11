#include <bits/stdc++.h>

using namespace std;

int insertionSort(int n, vector<int> &arr)
{
    int shift = 0;

    for (int i = 1; i < n; i++) {
        int value = arr[i];

        int j = i - 1;
        while (j >= 0 && arr[j] > value) {
            arr[j + 1] = arr[j];

            j -= 1;

            shift += 1;
        }

        arr[j + 1] = value;
    }

    return shift;
}

int main()
{

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    cout << insertionSort(n, arr) << '\n';
}
