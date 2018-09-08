#include <iostream>

using namespace std;

void multiply(long long F[2][2], long long M[2][2])
{
    long long a = (F[0][0] * M[0][0]) + (F[0][1] * M[1][0]);
    long long b = (F[0][0] * M[0][1]) + (F[0][1] * M[1][1]);
    long long c = (F[1][0] * M[0][0]) + (F[1][1] * M[1][0]);
    long long d = (F[1][0] * M[0][1]) + (F[1][1] * M[1][1]);

    F[0][0] = a;
    F[0][1] = b;
    F[1][0] = c;
    F[1][1] = d;
}

void power(long long F[2][2], long long n)
{
    if (n == 0 || n == 1)
        return;

    power(F, n / 2);
    multiply(F, F);

    long long M[2][2] = {{1, 1}, {1, 0}};
    if (n % 2 != 0) {
        multiply(F, M);
    }
}

long long fb(long long n)
{
    if (n == 0)
        return 0;

    long long F[2][2] = {{1, 1}, {1, 0}};
    power(F, n - 1);
    return F[0][0];
}

long long ft(long long n) { return 2 * (fb(n + 2) - 1) - n; }

int main()
{
    long long t, n, m;

    cin >> t;
    while (t--) {
        cin >> n >> m;

        long long result = (ft(n) + m) % m;
        if (result < 0)
            result += m;
        cout << result % m << endl;
    }
}
