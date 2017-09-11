#include <bits/stdc++.h>

using namespace std;

void insertionSort(int n, vector<int> &arr)
{
    for (int i = 1; i < n; i++) {
        int value = arr[i];

        int j = i - 1;
        while (j >= 0 && arr[j] > value) {
            arr[j + 1] = arr[j];

            j -= 1;
        }

        arr[j + 1] = value;
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << (i == n - 1 ? '\n' : ' ');
    }
}

int main()
{

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    insertionSort(n, arr);
}
