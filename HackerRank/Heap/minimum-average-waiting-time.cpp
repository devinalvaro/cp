#include <bits/stdc++.h>

using namespace std;

bool compare(const pair<long long, long long> &a,
             const pair<long long, long long> &b)
{
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

int main()
{
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    vector<pair<long long, long long>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].second >> a[i].first;
    }
    sort(a.begin(), a.end(), compare);

    priority_queue<pair<long long, long long>,
                   vector<pair<long long, long long>>,
                   greater<pair<long long, long long>>>
        heap;

    long long current_time = 0, total_waiting_time = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0 || a[i].second <= current_time) {
            if (heap.empty())
                current_time = max(current_time, a[i].second);
            heap.push(a[i]);
        } else if (!heap.empty()) {
            while (!heap.empty() && a[i].second > current_time) {
                pair<long long, long long> current_order = heap.top();
                heap.pop();

                current_time += current_order.first;

                total_waiting_time += (current_time - current_order.second);
            }

            if (heap.empty())
                current_time = max(current_time, a[i].second);
            heap.push(a[i]);
        }
    }

    while (!heap.empty()) {
        pair<long long, long long> current_order = heap.top();
        heap.pop();

        current_time += current_order.first;

        total_waiting_time += (current_time - current_order.second);
    }

    cout << total_waiting_time / n << '\n';
}
