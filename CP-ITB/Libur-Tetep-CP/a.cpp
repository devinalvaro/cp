#include <cmath>
#include <iostream>

using namespace std;

int main()
{
    int n, t, k, d;
    cin >> n >> t >> k >> d;

    int notBuildTime = ceil((float)n / (float)k) * t;
    int buildTime = 0;

    while (n > 0) {
        buildTime += 1;

        if (buildTime % t == 0) {
            n -= k;
        }

        if ((buildTime - d > 0) && (buildTime - d) % t == 0) {
            n -= k;
        }
    }

    if (buildTime < notBuildTime) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
