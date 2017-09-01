#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    stack<int> st, mt;

    while (n--) {
        int t;
        cin >> t;

        if (t == 1) {
            int x;
            cin >> x;

            st.push(x);
            if (mt.empty() || x > mt.top()) {
                mt.push(x);
            } else {
                mt.push(mt.top());
            }
        } else if (t == 2) {
            st.pop();
            mt.pop();
        } else {
            cout << mt.top() << '\n';
        }
    }
}
