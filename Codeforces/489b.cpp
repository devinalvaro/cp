#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int total = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (abs(a[i] - b[j]) <= 1) {
                total++;
                b[j] = -1;
                break;
            }
        }
    }
    cout << total << endl;
}
