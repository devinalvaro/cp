#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> first(n), second(n - 1), third(n - 2);
    for (int i = 0; i < n; i++) {
        cin >> first[i];
    }
    for (int i = 0; i < n - 1; i++) {
        cin >> second[i];
    }
    for (int i = 0; i < n - 2; i++) {
        cin >> third[i];
    }
    sort(first.begin(), first.end());
    sort(second.begin(), second.end());
    sort(third.begin(), third.end());

    for (int i = 0; i < n; i++) {
        if (i == n - 1 || first[i] != second[i]) {
            cout << first[i] << endl;
            break;
        }
    }
    for (int i = 0; i < n - 1; i++) {
        if (i == n - 2 || second[i] != third[i]) {
            cout << second[i] << endl;
            break;
        }
    }
}
