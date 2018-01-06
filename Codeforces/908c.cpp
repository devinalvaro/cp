#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, r;
    cin >> n >> r;

    vector<int> x(n);
    vector<double> answers(n);

    for (int i = 0; i < n; i++) {
        cin >> x[i];

        answers[i] = r;

        for (int j = 0; j < i; j++) {
            double cathetus = sqrt((4 * r * r) - ((x[j] - x[i]) * (x[j] - x[i])));

            if (cathetus < 0)
                continue;

            answers[i] = max(answers[i], answers[j] + cathetus);
        }
    }

    for (int i = 0; i < n; i++) {
        cout << fixed << setprecision(9) << answers[i]
             << (i == n - 1 ? '\n' : ' ');
    }

    return 0;
}
