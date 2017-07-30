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

int main()
{
    int n, k;
    cin >> n >> k;

    if (n == 0) {
        cout << 0 << endl;

        return 0;
    }

    int temp = n;
    vector<int> num;
    while (temp > 0) {
        num.push_back(temp % 10);
        temp /= 10;
    }

    if ((int)num.size() == k && (n % (int)pow(10, k) != 0)) {
        cout << num.size() - 1 << endl;

        return 0;
    }
    if ((int)num.size() < k) {
        cout << num.size() - 1 << endl;

        return 0;
    }

    int i = 0, c = 0, r = 0;
    while (c < k && i < (int)num.size()) {
        if (num[i] == 0) {
            c++;
        } else {
            r++;
        }
        i++;
    }

    if (c < k) {
        cout << (int)num.size() - 1 << endl;

        return 0;
    }

    cout << r << endl;
}
