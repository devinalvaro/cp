#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);

    int q;
    cin >> q;

    stack<int> rearStack, frontStack;

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int x;
            cin >> x;

            rearStack.push(x);
        } else if (frontStack.empty()) {
            while (!rearStack.empty()) {
                frontStack.push(rearStack.top());
                rearStack.pop();
            }
        }

        if (type == 2) {
            frontStack.pop();
        } else if (type == 3) {
            cout << frontStack.top() << '\n';
        }
    }
}
