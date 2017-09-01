#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);

    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;

    vector<int> v1, v2, v3;
    int h1, h2, h3;
    for (int i = 0; i < n1; i++) {
        int h;
        cin >> h;

        v1.push_back(h);
        h1 += h;
    }
    for (int i = 0; i < n2; i++) {
        int h;
        cin >> h;

        v2.push_back(h);
        h2 += h;
    }
    for (int i = 0; i < n3; i++) {
        int h;
        cin >> h;

        v3.push_back(h);
        h3 += h;
    }

    stack<int> s1, s2, s3;
    for (int i = n1 - 1; i >= 0; i--) {
        s1.push(v1[i]);
    }
    for (int i = n2 - 1; i >= 0; i--) {
        s2.push(v2[i]);
    }
    for (int i = n3 - 1; i >= 0; i--) {
        s3.push(v3[i]);
    }

    while (h1 != h2 || h2 != h3) {
        int h = max(h1, max(h2, h3));

        if (h1 == h) {
            h1 -= s1.top();
            s1.pop();
        } else if (h2 == h) {
            h2 -= s2.top();
            s2.pop();
        } else if (h3 == h) {
            h3 -= s3.top();
            s3.pop();
        }

        if (h1 == 0 || h2 == 0 || h3 == 0)
            break;
    }

    if (h1 == 0 || h2 == 0 || h3 == 0) {
        cout << 0 << '\n';
    } else {
        cout << h1 << '\n';
    }
}
