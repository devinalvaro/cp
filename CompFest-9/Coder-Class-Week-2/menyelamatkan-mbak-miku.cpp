#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

void flood_fill(int a, int b, int r, int c, vector<int> &status,
                vector<vector<int>> &city_id)
{
    for (int i = a - 1; i >= 1 && b + 1 <= c; i--) {
        for (int j = b + 1; j <= c; j++) {
            if (status[city_id[i][j]] == 0)
                break;

            status[city_id[i][j]] = 0;
        }
    }

    for (int i = a + 1; i <= r && b - 1 >= 1; i++) {
        for (int j = b - 1; j >= 1; j--) {
            if (status[city_id[i][j]] == 0)
                break;

            status[city_id[i][j]] = 0;
        }
    }
}

long long id(long long i, long long j, long long r, long long c, long long k,
             long long h)
{
    return ((((((i - 1) * c) + j) * k) + h) % (r * c)) + 1;
}

vector<vector<int>> city_id;
vector<pair<int, int>> city_pos;
vector<int> status;

int main()
{
    ios_base::sync_with_stdio(0);

    city_pos.assign(5e6 + 5, pair<int, int>());

    int t;
    cin >> t;
    while (t--) {
        int r, c, k, h;
        cin >> r >> c >> k >> h;

        city_id.assign(r + 1, vector<int>(c + 1));

        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                city_id[i][j] = id(i, j, r, c, k, h);

                city_pos[city_id[i][j]] = make_pair(i, j);
            }
        }

        status.assign(5e6 + 5, 1);

        int path_length = 0;
        for (int id = 1; id <= r * c && path_length < r + c; id++) {
            int i = city_pos[id].first;
            int j = city_pos[id].second;

            if (status[city_id[i][j]] == 1) {
                status[city_id[i][j]] = 2;

                path_length++;

                flood_fill(i, j, r, c, status, city_id);
            }
        }

        vector<int> result(r + c + 5);
        result[0] = city_id[1][1];

        int i = 1, j = 1, l = 1;
        while (i != r || j != c) {
            if (j + 1 <= c && status[city_id[i][j + 1]] == 2) {
                j++;
            } else if (i + 1 <= r && status[city_id[i + 1][j]] == 2) {
                i++;
            } else if (j - 1 >= 1 && status[city_id[i][j - 1]] == 2) {
                j--;
            } else if (i - 1 >= 1 && status[city_id[i - 1][j]] == 2) {
                i--;
            }

            result[l++] = city_id[i][j];
        }

        if (l <= 200) {
            for (int i = 0; i < l; i++) {
                cout << setfill('0') << setw(7) << result[i] << '\n';
            }
        } else {
            for (int i = 0; i < 100; i++) {
                cout << setfill('0') << setw(7) << result[i] << '\n';
            }

            for (int i = l - 100; i < l; i++) {
                cout << setfill('0') << setw(7) << result[i] << '\n';
            }
        }
    }
}
