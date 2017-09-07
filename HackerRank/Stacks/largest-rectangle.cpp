#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    vector<long long> height(n);
    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }
    height.push_back(LLONG_MIN);

    stack<int> heightStack;
    long long largest = LLONG_MIN;

    for (int i = 0; i < n + 1;) {
        if (heightStack.empty() || height[i] > height[heightStack.top()]) {
            heightStack.push(i);

            i++;
        } else {
            int j = heightStack.top();
            heightStack.pop();

            largest =
                max(largest,
                    height[j] * (long long)(heightStack.empty()
                                                ? i
                                                : i - 1 - heightStack.top()));
        }
    }

    cout << largest << endl;
}
