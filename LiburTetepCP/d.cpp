#include <iostream>

using namespace std;

int main()
{
    int n, l;

    while (true) {
        cin >> n >> l;

        if (n == 0 && l == 0) {
            break;
        }

        long long mul = 1, sum = 0;
        for (int i = 1; i <= l; i++) {
            mul *= n;
            mul %= (1000000000 + 7);
            sum += mul;
            sum %= (1000000000 + 7);
        }

        cout << sum << endl;
    }
}
