#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ll long long
#define ve vector
#define ii pair<int, int>
#define iv pair<int, ii>

int main() {
    int n;
    cin >> n;

    bool rated = false;
    ve<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        if (a[i] != b[i]) {
            rated = true;
        }
    }

    if (rated) {
        cout << "rated\n";
        return 0;
    }

    for (int i = 1; i < n; i++) {
        if (a[i - 1] < a[i]) {
            cout << "unrated\n";
            return 0;
        }
    }

    cout << "maybe\n";

    return 0;
}
