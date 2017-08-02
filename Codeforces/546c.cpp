#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

int limits[] = {1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800};

int main()
{
    int n, k1, k2;
    cin >> n;

    cin >> k1;
    deque<int> d1(k1);
    for (int i = 0; i < k1; i++) {
        cin >> d1[i];
    }

    cin >> k2;
    deque<int> d2(k2);
    for (int i = 0; i < k2; i++) {
        cin >> d2[i];
    }

    int fights = 0, limit = limits[n];
    while (fights <= limit) {
        int card_a = d1.front();
        d1.pop_front();
        int card_b = d2.front();
        d2.pop_front();

        if (card_a > card_b) {
            d1.push_back(card_b);
            d1.push_back(card_a);
        } else {
            d2.push_back(card_a);
            d2.push_back(card_b);
        }

        fights++;

        if (d1.empty() || d2.empty())
            break;
    }

    if (fights > limit) {
        cout << -1 << endl;
    } else {
        cout << fights << ' ' << (d1.empty() ? "2" : "1") << endl;
    }
}
