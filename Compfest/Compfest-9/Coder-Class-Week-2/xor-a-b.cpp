#include <algorithm>
#include <bitset>
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

bool is_odd(unsigned long long n) { return n & 1; }

bool is_even(unsigned long long n) { return !is_odd(n); }

bool is_doubly_even(unsigned long long n)
{
    return is_even(n) && is_even(n / 2);
}

bool is_singly_even(unsigned long long n)
{
    return is_even(n) && is_odd(n / 2);
}

unsigned long long round_up(unsigned long long n)
{
    if (n == 0) {
        return 1;
    }

    return pow(2, (unsigned long long)log2(n) + 1) - 1;
}

unsigned long long round_down(unsigned long long n)
{
    if (n == 0) {
        return 0;
    }

    return pow(2, (unsigned long long)log2(n));
}

int main()
{
    ios_base::sync_with_stdio(0);

    unsigned long long a, b;
    cin >> a >> b;

    unsigned long long result = 0;

    if (is_odd(a)) {
        result ^= a;

        a++;
    }

    if (is_odd(b - a + 1)) {
        result ^= b;

        if (is_singly_even(b - a)) {
            result ^= (unsigned long long)1;
        }
    } else if (is_singly_even(b - a + 1)) {
        result ^= (unsigned long long)1;
    }

    string s = bitset<64>(result).to_string();
    if (s.find("1") == string::npos) {
        cout << 0 << '\n';
    } else {
        cout << s.substr(s.find("1")) << '\n';
    }
}
