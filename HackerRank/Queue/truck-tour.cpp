#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    int fuel = 0, start = 0;
    for (int i = 0; i < n; i++) {
        int petrol, dist;
        cin >> petrol >> dist;

        fuel += petrol - dist;
        if (fuel < 0) {
            fuel = 0;
            start = i + 1;
        }
    }

    cout << start << '\n';
}
