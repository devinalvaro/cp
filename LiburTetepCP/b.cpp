#include <iostream>

using namespace std;

int josephus(int n, int k)
{
    if (n == 1)
        return 1;
    return (josephus(n - 1, k) + k - 1) % n + 1;
}

int main()
{
    int t, n, k;

    cin >> t;
    for (int c = 1; c <= t; c++) {
        cin >> n >> k;
        cout << "Case " << c << ": " << josephus(n, k) << endl;
    }
}
