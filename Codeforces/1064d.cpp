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

#define ceil(x, y) (x + y - 1) / y
#define spnl(i, n) " \n"[(i == n - 1)]

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, -1, 0, 1};
int dx[] = {0, -1, 0, 0};
int dy[] = {0, 0, 0, -1};

struct Element {
    int r, c, x, y;

    Element(int r, int c, int x, int y) {
        this->r = r;
        this->c = c;
        this->x = x;
        this->y = y;
    }
};

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int r, c;
    scanf("%d %d", &r, &c);
    r--, c--;

    int x, y;
    scanf("%d %d", &x, &y);

    ve<string> area(n);
    for (int i = 0; i < n; i++) {
        cin >> area[i];
    }
    area[r][c] = '+';

    deque<Element> q;
    q.push_front(Element(r, c, x, y));

    while (!q.empty()) {
        Element u = q.front();
        q.pop_front();

        for (int i = 0; i < 4; i++) {
            int vr = u.r + dr[i];
            int vc = u.c + dc[i];
            int vx = u.x + dx[i];
            int vy = u.y + dy[i];

            if (vr < 0 || vr >= n || vc < 0 || vc >= m || vx < 0 || vy < 0) {
                continue;
            }

            if (area[vr][vc] == '.') {
                area[vr][vc] = '+';

                Element v(vr, vc, vx, vy);
                if (i & 1) {
                    q.push_back(v);
                } else {
                    q.push_front(v);
                }
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cnt += (area[i][j] == '+');
        }
    }
    printf("%d\n", cnt);

    return 0;
}
