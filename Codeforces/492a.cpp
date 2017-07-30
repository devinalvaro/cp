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

int cubes_in_level(int height)
{
    if (height == 1)
        return 1;
    return height + cubes_in_level(height - 1);
}

int main()
{
    int n;
    cin >> n;

    int cubes = 0, height = 0;
    while (cubes + cubes_in_level(height + 1) <= n) {
        cubes += cubes_in_level(++height);
    }
    cout << height << endl;
}
