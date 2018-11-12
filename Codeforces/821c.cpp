#include <bits/stdc++.h>

using namespace std;

#define fi  first
#define se  second
#define pb  push_back
#define ll  long long
#define ve  vector
#define pq  priority_queue
#define um  unordered_map
#define us  unordered_set
#define pii pair<int, int>
#define pll pair<ll, ll>

#define ceil(x, y) ((x + y - 1) / y)
#define spnl(i, n) (i == n - 1 ? '\n' : ' ')
#define nend(i, c) (i == c.end() ? i : next(i))

int main() {
    int n;
    scanf("%d", &n);
    n <<= 1;

    stack<int> st;

    int c = 1, ro = 0;

    while (n--) {
        string s;
        cin >> s;

        if (s == "add") {
            int x;
            scanf("%d", &x);
            st.push(x);
            continue;
        }

        if (!st.empty()) {
            if (st.top() == c) {
                st.pop();
            } else {
                while (!st.empty()) {
                    st.pop();
                }
                ro++;
            }
        }

        c++;
    }

    printf("%d\n", ro);

    return 0;
}
