#include <bits/stdc++.h>

using namespace std;

int doubleMedian(const vector<int> &frequency, int d)
{
    int sum = 0;
    int lowMedian = -1, highMedian = -1;

    for (int i = 0; i <= 200; i++) {
        sum += frequency[i];

        if (lowMedian == -1 && sum >= int(floor((d + 1) / 2.0))) {
            lowMedian = i;
        }
        if (highMedian == -1 && sum >= int(ceil((d + 1) / 2.0))) {
            highMedian = i;
        }
    }

    return lowMedian + highMedian;
}

int main()
{
    ios_base::sync_with_stdio(0);

    int n, d;
    cin >> n >> d;

    vector<int> expenditures(n), frequency(201, 0);
    for (int i = 0; i < n; i++) {
        cin >> expenditures[i];
    }

    for (int i = 0; i < d; i++) {
        frequency[expenditures[i]] += 1;
    }

    int notifications = 0;

    for (int i = d; i < n; i++) {
        if (expenditures[i] >= doubleMedian(frequency, d)) {
            notifications += 1;
        }

        frequency[expenditures[i - d]] -= 1;
        frequency[expenditures[i]] += 1;
    }

    cout << notifications << '\n';
}
