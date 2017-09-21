#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    unordered_map<int, int> appId, appScreen;
    int screenNum = 1, screenAmount = 0;
    for (int i = 0; i < n; i++) {
        appId[a[i]] = i;

        appScreen[a[i]] = screenNum;
        screenAmount++;

        if (screenAmount == k) {
            screenNum++;
            screenAmount = 0;
        }
    }

    long long moves = 0;
    for (int i = 0; i < m; i++) {
        moves += (long long)(appScreen[b[i]]);

        int id = appId[b[i]];

        if (id == 0)
            continue;

        if (appScreen[a[id - 1]] < appScreen[a[id]]) {
            int temp = appScreen[a[id]];
            appScreen[a[id]] = appScreen[a[id - 1]];
            appScreen[a[id - 1]] = temp;
        }

        swap(a[id], a[id - 1]);

        int temp = appId[a[id]];
        appId[a[id]] = appId[a[id - 1]];
        appId[a[id - 1]] = temp;
    }

    cout << moves << '\n';
}
