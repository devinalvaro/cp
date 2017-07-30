#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> arr1(n), arr2(n);

    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
        arr2[i] = arr1[i];
    }

    vector<pair<int, int>> answer;

    sort(arr2.begin(), arr2.end());
    for (int i = 0; i < n; i++) {
        if (arr2[i] == arr1[i])
            continue;
        for (int j = i + 1; j < n; j++) {
            if (arr2[i] == arr1[j]) {
                int temp = arr1[j];
                arr1[j] = arr1[i];
                arr1[i] = temp;

                answer.push_back(pair<int, int>(i, j));

                break;
            }
        }
    }

    cout << answer.size() << endl;
    for (int i = 0; i < (int)answer.size(); i++) {
        cout << answer[i].first << ' ' << answer[i].second << endl;
    }
}
