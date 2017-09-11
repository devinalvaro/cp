#include <bits/stdc++.h>

using namespace std;

int minSwap(int n, const vector<pair<int, int>> &b)
{
    vector<bool> visited(n, false);

    int swaps = 0;

    for (int i = 0; i < n; i++) {
        if (visited[i] || b[i].second == i)
            continue;

        int cycle = 0;

        int j = i;
        while (!visited[j]) {
            visited[j] = true;

            j = b[j].second;
            cycle++;
        }

        swaps += (cycle - 1);
    }

    return swaps;
}

int main()
{
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<pair<int, int>> b(n);
    for (int i = 0; i < n; i++) {
        b[i] = make_pair(a[i], i);
    }

    sort(b.begin(), b.end());
    int swaps = minSwap(n, b);

    reverse(b.begin(), b.end());
    swaps = min(swaps, minSwap(n, b));

    cout << swaps << '\n';
}
