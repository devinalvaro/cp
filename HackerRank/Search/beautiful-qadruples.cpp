#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);

    int abcd[4];
    for (int i = 0; i < 4; i++) {
        cin >> abcd[i];
    }

    sort(abcd, abcd + 4);
    int a = abcd[0], b = abcd[1], c = abcd[2], d = abcd[3];

    vector<int> total(3001, 0);
    vector<vector<int>> ugly(3001, vector<int>(4096, 0));

    for (int i = 1; i <= a; i++) {
        for (int j = i; j <= b; j++) {
            total[j] += 1;
        }
    }
    for (int i = 1; i <= 3000; i++) {
        total[i] += total[i - 1];
    }

    for (int i = 1; i <= a; i++) {
        for (int j = i; j <= b; j++) {
            ugly[j][i ^ j] += 1;
        }
    }
    for (int i = 1; i <= 3000; i++) {
        for (int j = 0; j < 4096; j++) {
            ugly[i][j] += ugly[i - 1][j];
        }
    }

    long long beautiful = 0;

    for (int i = 1; i <= c; i++) {
        for (int j = i; j <= d; j++) {
            beautiful += total[i] - ugly[i][i ^ j];
        }
    }

    cout << beautiful << '\n';
}
