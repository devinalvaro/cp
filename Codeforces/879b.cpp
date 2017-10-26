#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    long long k;
    cin >> n >> k;

    int max_val = INT_MIN;
    queue<int> a;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        max_val = max(max_val, x);

        a.push(x);
    }

    if (k >= n - 1) {
        cout << max_val << '\n';

        return 0;
    }

    int current_winner = a.front();
    a.pop();

    int win = 0;

    for (int i = 0; i < n; i++) {
        while (true) {
            if (current_winner > a.front()) {
                a.push(a.front());
                a.pop();

                win++;

                if (win == k) {
                    cout << current_winner << '\n';

                    return 0;
                }
            } else {
                a.push(current_winner);

                current_winner = a.front();
                a.pop();

                win = 1;

                break;
            }
        }
    }

    return 0;
}
