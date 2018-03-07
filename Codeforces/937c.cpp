#include <bits/stdc++.h>

using namespace std;

int main() {
    long long k, d, t;
    cin >> k >> d >> t;

    long long period;
    if (k <= d) {
        period = d;
    } else {
        period = ceil((double)k / d) * d;
    }

    long long parts = 2 * t;
    long long parts_per_period = k + period;
    long long period_count = parts / parts_per_period;
    long long carry = parts - (period_count * parts_per_period);

    double cooking_time = period_count * period;

    if (carry <= 2 * k) {
        cooking_time += (double)carry / 2;
    } else {
        cooking_time += (carry - k);
    }

    cout << fixed << setprecision(9) << cooking_time << '\n';

    return 0;
}
