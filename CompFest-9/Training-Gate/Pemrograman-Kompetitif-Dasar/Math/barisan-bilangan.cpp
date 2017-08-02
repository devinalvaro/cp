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

long long gcd(long long a, long long b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int main()
{
    ios_base::sync_with_stdio(0);

    unsigned long long n, a, b;
    cin >> n >> a >> b;

    if (a == b) {
        cout << n / a << '\n';
    } else {
        cout << (n / a) + (n / b) - (n / (a * b / gcd(a, b))) << '\n';
    }
}
