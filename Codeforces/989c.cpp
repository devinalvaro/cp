#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define ll long long
#define ve vector
#define pq priority_queue
#define um unordered_map
#define us unordered_set

#define pii pair<int, int>
#define pll pair<ll, ll>

char table[50][50];
map<char, int> cnt;

char defaultChar(int i, int j) {
    if (i < 25 && j < 25) {
        return 'a';
    } else if (i < 25 && j >= 25) {
        return 'b';
    } else if (i >= 25 && j < 25) {
        return 'c';
    } else {
        return 'd';
    }
}

bool isBorder(int i, int j) {
    return i == 24 || i == 25 || j == 24 || j == 25;
}

bool isDone() {
    return cnt['a'] == 0 && cnt['b'] == 0 && cnt['c'] == 0 && cnt['d'] == 0;
}

char upperNeighbour(int i, int j) {
    if (i > 0) {
        return table[i - 1][j];
    }
    return '.';
}

char leftNeighbour(int i, int j) {
    if (j > 0) {
        return table[i][j - 1];
    }
    return '.';
}

char upperLeftNeighbour(int i, int j) {
    if (i > 0 && j > 0) {
        return table[i - 1][j - 1];
    }
    return '.';
}

char upperRightNeighbour(int i, int j) {
    if (i > 0 && j + 1 < 50) {
        return table[i - 1][j + 1];
    }
    return '.';
}

bool isOutOfBound(int i, int j) {
    return i < 0 || i >= 50 || j < 0 || j >= 50;
}

bool isBlocking(int i, int j) {
    if (upperNeighbour(i, j) == defaultChar(i, j) &&
        (isOutOfBound(i - 1, j - 1) || upperLeftNeighbour(i, j) != defaultChar(i, j)) &&
        (isOutOfBound(i - 1, j + 1) || upperRightNeighbour(i, j) != defaultChar(i, j))) {
        return true;
    }

    if (upperLeftNeighbour(i, j) == defaultChar(i, j) &&
        (isOutOfBound(i, j - 1) || leftNeighbour(i, j) != defaultChar(i, j)) &&
        (isOutOfBound(i - 1, j) || upperNeighbour(i, j) != defaultChar(i, j))) {
        return true;
    }

    return false;
}

void eliminateCandidates(set<char> &candidates) {
    for (auto it = cnt.begin(); it != cnt.end(); it++) {
        if (it->second == 0) {
            candidates.erase(it->first);
        }
    }
}

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 50; j++) {
            table[i][j] = defaultChar(i, j);
        }
    }
    a--, b--, c--, d--;

    cnt['a'] = a, cnt['b'] = b, cnt['c'] = c, cnt['d'] = d;

    for (int i = 0; i < 50 && !isDone(); i++) {
        for (int j = 0; j < 50 && !isDone(); j++) {
            if (isBorder(i, j)) {
                continue;
            }

            set<char> candidates = {'a', 'b', 'c', 'd'};
            candidates.erase(defaultChar(i, j));
            candidates.erase(upperNeighbour(i, j));
            candidates.erase(leftNeighbour(i, j));
            eliminateCandidates(candidates);

            if (candidates.size() == 0 || isBlocking(i, j)) {
                continue;
            }

            table[i][j] = *candidates.begin();
            cnt[*candidates.begin()]--;
        }
    }

    cout << 50 << ' ' << 50 << endl;
    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 50; j++) {
            cout << table[i][j];
        }
        cout << endl;
    }

    return 0;
}
