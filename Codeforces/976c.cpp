#include <bits/stdc++.h>

using namespace std;

bool cmp(const pair<pair<int, int>, int> &a,
         const pair<pair<int, int>, int> &b) {
    if (a.first.first == b.first.first) {
        return a.first.second > b.first.second;
    }
    return a.first.first < b.first.first;
}

int main() {
    int n;
    scanf("%d", &n);

    vector<pair<pair<int, int>, int>> s(n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &s[i].first.first, &s[i].first.second);
        s[i].second = i + 1;
    }

    sort(s.begin(), s.end(), cmp);

    int max_so_far = s[0].first.second;
    int max_so_far_id = s[0].second;
    for (int i = 1; i < n; i++) {
        if (s[i].first.second <= max_so_far) {
            cout << s[i].second << ' ' << max_so_far_id << '\n';

            return 0;
        }

        if (s[i].first.second > max_so_far) {
            max_so_far = s[i].first.second;
            max_so_far_id = s[i].second;
        }
    }

    cout << "-1 -1\n";

    return 0;
}
