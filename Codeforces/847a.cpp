#include <bits/stdc++.h>

using namespace std;

int findHead(int i, const vector<int> &l, const vector<int> &r,
             vector<int> &head)
{
    if (head[i] != -1)
        return head[i];

    if (l[i] == 0)
        return head[i] = i;

    return head[i] = findHead(l[i], l, r, head);
}

int findTail(int i, const vector<int> &l, const vector<int> &r,
             vector<int> &tail)
{
    if (tail[i] != -1)
        return tail[i];

    if (r[i] == 0)
        return tail[i] = i;

    return tail[i] = findTail(r[i], l, r, tail);
}

int main()
{
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    vector<int> l(n + 1), r(n + 1), head(n + 1, -1), tail(n + 1, -1);
    for (int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i];
    }

    for (int i = 1; i <= n; i++) {
        head[i] = findHead(i, l, r, head);
        tail[i] = findTail(i, l, r, tail);
    }

    int headNum = 0;
    for (int i = 1; i <= n; i++) {
        if (i == head[i]) {
            headNum++;
        }
    }

    for (int i = 1; i <= n && headNum > 1; i++) {
        if (i != tail[i])
            continue;

        for (int j = 1; j <= n; j++) {
            if (j != head[j] || j == head[i] || i == tail[j])
                continue;

            r[i] = j;
            l[j] = i;

            int k = i;
            while (k != 0) {
                tail[k] = tail[j];
                k = l[k];
            }

            k = j;
            while (k != 0) {
                head[k] = head[i];
                k = r[k];
            }

            headNum--;

            break;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << l[i] << ' ' << r[i] << '\n';
    }
}
