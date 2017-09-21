#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    vector<int> a(n + 1);
    vector<long long> sum(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];

        sum[i] = a[i] + sum[i - 1];
    }

    vector<int> d(n + 1);
    set<int> destroyed;
    for (int i = 1; i <= n; i++) {
        cin >> d[i];

        destroyed.insert(i);
    }

    vector<long long> answer(n + 1);
    long long maxSum = 0;

    for (int i = n; i >= 1; i--) {
        answer[i] = maxSum;

        auto iter = destroyed.find(d[i]);
        auto temp1 = iter, temp2 = iter;
        auto begin = destroyed.begin(), end = destroyed.end();

        int hi = (iter == --end ? n + 1 : *(++temp1));
        int low = (iter == begin ? 0 : *(--temp2));

        destroyed.erase(iter);

        maxSum = max(maxSum, (long long)sum[hi - 1] - (long long)sum[low]);
    }

    for (int i = 1; i <= n; i++) {
        cout << answer[i] << '\n';
    }
}
