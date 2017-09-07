#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);

    int q;
    cin >> q;

    while (q--) {
        int n;
        cin >> n;

        vector<int> dist(n + 1, -1);
        dist[n] = 0;

        queue<int> nums;
        nums.push(n);

        while (!nums.empty()) {
            int num = nums.front();
            nums.pop();

            if (num - 1 >= 0 && dist[num - 1] == -1) {
                dist[num - 1] = dist[num] + 1;

                if (num - 1 == 0)
                    break;

                nums.push(num - 1);
            }

            for (int i = 2; i * i <= num; i++) {
                if (num % i == 0 && dist[num / i] == -1) {
                    dist[num / i] = dist[num] + 1;
                    
                    if (num / i == 0)
                        break;

                    nums.push(num / i);
                }
            }
        }

        cout << dist[0] << '\n';
    }
}
