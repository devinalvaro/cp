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
    vector<long long> rgb(3);
    for (int i = 0; i < 3; i++) {
        cin >> rgb[i];
    }

    sort(rgb.begin(), rgb.end());

    long long sum = (rgb[0] + rgb[1] + rgb[2]) / 3;
    if (rgb[0] + rgb[1] < sum) {
        sum = rgb[0] + rgb[1];
    }

    cout << sum << endl;
}
