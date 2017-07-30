#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    int n, m, b, g;
    cin >> n >> m;

    cin >> b;
    vector<int> boys(b);
    for (int i = 0; i < b; i++) {
        cin >> boys[i];
    }

    cin >> g;
    vector<int> girls(g);
    for (int i = 0; i < g; i++) {
        cin >> girls[i];
    }

    int gnm = gcd(n, m);
    bool happy;

    for (int i = 0; i < gnm; i++) {
        happy = false;
        for (int j = 0; j < b; j++) {
            if (boys[j] % gnm == i) {
                happy = true;
                break;
            }
        }
        for (int j = 0; j < g; j++) {
            if (girls[j] % gnm == i) {
                happy = true;
                break;
            }
        }
        if (!happy) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
}
