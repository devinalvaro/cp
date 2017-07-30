#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

int beauty(int n, int k, string s)
{
    int ret = 0, l = 0, c = 0;

    for (int r = 0; r < n; r++) {
        if (s[r] == 'b')
            c++;

        while (l < r && c > k) {
            if (s[l] == 'b')
                c--;
            l++;
        }

        if (c <= k)
            ret = max(ret, r - l + 1);
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);

    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    int ans = beauty(n, k, s);
    for (int i = 0; i < n; i++) {
        s[i] = (s[i] == 'a' ? 'b' : 'a');
    }
    ans = max(ans, beauty(n, k, s));

    cout << ans << '\n';
}
