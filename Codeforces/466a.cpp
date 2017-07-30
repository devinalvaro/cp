#include <iostream>

using namespace std;

int main()
{
    int n, m, a, b;
    cin >> n >> m >> a >> b;

    int sum1 = a * n;
    int sum2 = (n / m) * b + (n % m) * a;
    int sum3 = ((n / m) + 1) * b;

    cout << min(sum1, min(sum2, sum3)) << endl;
}
